import binascii
import hashlib
import importlib.util
import sys
from argparse import ArgumentParser
from pathlib import Path
from typing import List

import triton
from triton.compiler.code_generator import kernel_suffix
from triton.backends.nvidia.driver import ty_to_cpp

desc = """
Triton ahead-of-time compiler:

This program compiles the kernel with name `kernel-name` in the file at the
provided `path` into self-contained C source-code that embeds the `cubin`
data along with utilities to load, unload and launch the kernel.

signature is provided as a list of (optionally divisibility-hinted) types
or constexpr values, e.g.

`compile.py --kernel-name kernel --signature "*fp32:16, i32:16, 1024, i32" --out-name kernel /path/to/kernel.py`

will compile triton.JITFunction of name `kernel` inside the file `/path/to/kernel.py`.
Said kernel will be specialized such that argument 0, 1 are assumed to be multiple of 16,
and argument 2 is assumed to be a compile-time constant of value 1024, i.e. it won't be part of the generated prototype.

The resulting entry point will have signature

CUresult kernel_{specialization_suffix}(CUstream stream, unsigned gX, unsigned gY, unsigned gZ, float* arg0, int32_t arg1, int32_t arg2)

Different such specialized entry points can be combined using the `linker.py` script.

NOTE: when resolving the scope of /path/to/kernel.py, the file will be executed from within its parent directory with the python interpreter
used to run this `compile.py` script
"""

class FakeTensor:

    def __init__(self, ptr_align, dtype) -> None:
        self.ptr_align = ptr_align
        self.dtype = dtype

    def data_ptr(self):
        return self.ptr_align

def kernel_to_c(
    kernel_jit_func,
    kernel_name: str,
    out_name: str,
    out_path: str,
    grid: list,
    ccinfo: triton.compiler.CompiledKernel,
):
    out_name = out_name if out_name else kernel_name
    out_path = Path(out_path) if out_path else Path(out_name)

    assert len(grid) == 3

    num_warps = ccinfo.metadata.num_warps
    num_stages = ccinfo.metadata.num_stages
    num_ctas = ccinfo.metadata.num_ctas
    cluster_dims = ccinfo.metadata.cluster_dims

    meta_sig = f"warps{num_warps}xstages{num_stages}"
    # sig_hash = hash_signature(signature + [meta_sig])
    
    sig_hash = ccinfo.hash


    def pytype_to_ty(s):
        if isinstance(s, (int, bool)):
            return "i64"
        elif isinstance(s, float):
            return "fp64"
        else:
            raise NotImplementedError()
    def pyval_to_cval_str(s):
        if isinstance(s, bool):
            return str(int(s))
        else:
            return str(s)
    accept_constexpr_types = (int, float, bool)

    signature = ccinfo.src.signature
    constants = ccinfo.src.constants
    attrs = ccinfo.src.attrs

    # hints = {i: constexpr(s.split(":")[1]) for i, s in enumerate(signature) if ":" in s}
    # hints = {k: v for k, v in hints.items() if v is not None}
    # constants = {i: constexpr(s) for i, s in enumerate(signature)}
    # constants = {k: v for k, v in constants.items() if v is not None}
    # signature = {i: s.split(":")[0] for i, s in enumerate(signature) if i not in constants}
    # const_sig = 'x'.join([str(v) for v in constants.values()])
    # doc_string = [f"{kernel_jit_func.arg_names[i]}={constants[i]}" for i in constants.keys()]
    doc_string = [f"{name}={value}" for name, value in constants.items()]
    doc_string += [f"num_warps={num_warps}", f"num_stages={num_stages}"]

    # # compile ast into cubin
    # for h in hints.values():
    #     assert h in [1, 16], f"Only 1 and 16 are valid hints, got {h}"
    # divisible_by_16 = [i for i, h in hints.items() if h == 16]
    # equal_to_1 = [i for i, h in hints.items() if h == 1]
    # attrs = triton.compiler.AttrsDescriptor(divisible_by_16=divisible_by_16, equal_to_1=equal_to_1)
    # for i in equal_to_1:
    #     constants.update({i: 1})
    # src = triton.compiler.ASTSource(fn=kernel, constants=constants, signature=signature, attrs=attrs)
    # opts = {"num_warps": num_warps, "num_stages": num_stages}
    # ccinfo = triton.compile(src, options=opts)
    arg_names = []
    arg_types = []
    for i, item in enumerate(signature.items()):
        arg_name = item[0]
        arg_type = item[1]
        if arg_name not in constants:
            arg_names += [arg_name]
            arg_types += [arg_type]

    const_sig = 'x'.join([str(v) for v in constants.values()])

    # dump C stub code
    suffix = kernel_suffix(signature.values(), attrs)
    func_name = '_'.join([out_name, sig_hash, suffix])
    hex_ = str(binascii.hexlify(ccinfo.asm["cubin"]))[2:-1]
    params = {
        "kernel_name": func_name,
        "triton_kernel_name": kernel_name,
        "bin_size": len(hex_),
        "bin_data": ", ".join([f"0x{x}{y}" for x, y in zip(hex_[::2], hex_[1::2])]),
        "signature": ", ".join([f"{ty_to_cpp(ty)} {name}" for name, ty in signature.items()]),
        "full_signature": ", ".join([f"{ty_to_cpp(ty)} {name}" for name, ty in signature.items()]),
        "constexpr": "; ".join([f"{ty_to_cpp(pytype_to_ty(value))}, {name}, {pyval_to_cval_str(value)}" 
                                for name, value in constants.items() 
                                if name not in signature.keys() and type(value) in accept_constexpr_types] + 
                               [f"int, num_warps, {num_warps}", f"int, num_stages, {num_stages}"]),
        "arg_pointers": ", ".join([f"&{arg}" for arg in arg_names]),
        "num_args": len(arg_names),
        "kernel_docstring": doc_string,
        "shared": ccinfo.metadata.shared,
        "num_warps": num_warps,
        "algo_info": '_'.join([const_sig, meta_sig]),
        "gridX": grid[0],
        "gridY": grid[1],
        "gridZ": grid[2],
        "_placeholder": "",
    }
    # print(f"const_sig={const_sig}")
    # print(f"meta_sig={meta_sig}")
    # print(f"signature={signature}")
    # print(f"constants={constants}")
    # print(f"kernel.arg_names={kernel.arg_names}")

    for ext in ['h', 'c']:
        template_path = Path(__file__).parent / f"compile.{ext}"
        with out_path.with_suffix(f".{sig_hash}_{suffix}.{ext}").open("w") as fp:
            fp.write(Path(template_path).read_text().format(**params))


