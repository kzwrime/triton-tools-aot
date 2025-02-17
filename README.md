
# Triton Tools AOT 小工具

修改自 triton/tools

注意：

1. 目前只支持 nvidia gpu
2. 同一组生成的 Kernel 的相同参数不允许使用不同类型，暂时还不支持泛型
3. 目前通过 triton 直接的后端自动识别，因此请确保编译时的卡和运行时的卡一致，多卡且卡不同的用户请确认使用哪张卡

```bash
export CUDA_DEVICE_ORDER=PCI_BUS_ID
export CUDA_VISIBLE_DEVICES=0
```

# 示例 examples/01-vector-add

简单方式

```bash
cd triton-tools-aot
export PYTHONPATH=$(pwd):$PYTHONPATH
cd examples/01-vector-add
./aot-compile.sh
```

生成的 kernel 在 `examples/01-vector-add/kernels/*`

生成的 wrapper 在 `examples/01-vector-add/add_kernel.c` 和 `examples/01-vector-add/add_kernel.c`

使用 `test_add_kernel.cu` 来进行测试

`generate_kernel.py` 写法

```python
import os,sys
import torch
import triton
import vector_add

from tools.compile2 import kernel_to_c, FakeTensor
from itertools import product

int_eq_1 = 1
int_align_16 = 16
int_normal = 17

func_args = {
    "x_ptr": [FakeTensor(16, torch.float32), FakeTensor(int_normal, torch.float32)],
    "y_ptr": [FakeTensor(16, torch.float32), FakeTensor(int_normal, torch.float32)],
    "output_ptr": [FakeTensor(16, torch.float32), FakeTensor(int_normal, torch.float32)],
    "n_elements": [int_align_16, int_normal],
    "BLOCK_SIZE": [64, 128],
}

kernel_name="add_kernel"
kernel_output_name="add_kernel"
output_path_with_prefix="./kernels/add_kernel"
default_grid=(1024,1,1)

count = 0
keys, values = zip(*func_args.items())
for config_values in product(*values):
    config = dict(zip(keys, config_values))
    
    # 假设需求是 x_ptr 和 y_ptr 的 align 肯定一样
    # 那么排除掉不符合条件的情况
    if config["x_ptr"].data_ptr() != config["y_ptr"].data_ptr():
        continue
    
    # configs.append(config)
    print(f"count={count}, config={config}")
    ccinfo = vector_add.add_kernel.warmup(grid=default_grid, **config)
    kernel_to_c(
        vector_add.add_kernel,
        kernel_name,
        kernel_output_name,
        output_path_with_prefix,
        default_grid,
        ccinfo,
    )
    count += 1
    print()
```

# 示例 examples/fused-moe

```bash
cd triton-tools-aot
export PYTHONPATH=$(pwd):$PYTHONPATH
cd examples/fused-moe
./aot-compile.sh
```

kernel 生成器是 `generate_kernel.py`，示例如下

```python
func_args = {
    "a_ptr": [FakeTensor(16, FP8_DTYPE)],
    "b_ptr": [FakeTensor(16, FP8_DTYPE)],
    "c_ptr": [FakeTensor(16, torch.bfloat16)],
    "a_scale_ptr": [FakeTensor(16, torch.float32)],
    "b_scale_ptr": [FakeTensor(16, torch.float32)],
    "topk_weights_ptr": [FakeTensor(16, torch.float32)],
    "sorted_token_ids_ptr": [FakeTensor(16, torch.int32)],
    "expert_ids_ptr": [FakeTensor(16, torch.int32)],
    "num_tokens_post_padded_ptr": [FakeTensor(16, torch.int32)],
    # Matrix dimensions
    "N": [int_align_16],
    "K": [int_align_16],
    "EM": [int_align_16],
    "num_valid_tokens": [int_normal],
    # The stride variables represent how much to increase the ptr by when
    # moving by 1 element in a particular dimension. E.g. `stride_am` is
    # how much to increase `a_ptr` by to get the element one row down
    # (A has M rows).
    "stride_am": [int_align_16],
    "stride_ak": [int_eq_1],
    "stride_be": [int_align_16],
    "stride_bk": [int_eq_1],
    "stride_bn": [int_align_16],
    "stride_cm": [int_align_16],
    "stride_cn": [int_eq_1],
    "stride_asm": [int_align_16, int_eq_1, int_normal],
    "stride_ask": [int_align_16, int_eq_1],
    "stride_bse": [int_align_16, int_normal],
    "stride_bsk": [int_align_16, int_eq_1],
    "stride_bsn": [int_align_16, int_eq_1, int_normal],
    # Block size for block-wise quantization
    "group_n": [128],
    "group_k": [128],
    # Meta-parameters
    "BLOCK_SIZE_M": [64],
    "BLOCK_SIZE_N": [64],
    "BLOCK_SIZE_K": [128],
    "GROUP_SIZE_M": [32],
    "MUL_ROUTED_WEIGHT": [0, 1],
    "top_k": [2, 1],
    "compute_type": [triton.language.bfloat16],
    "use_fp8_w8a8": [1],
    "use_int8_w8a16": [0],
    "num_warps": [4, 8],
    "num_stages": [3],
}
```

生成的 kernel 在 `examples/fused-moe/kernels/fused_moe_kernel_fp8/*`

生成的 wrapper 在 `examples/fused-moe/fused_moe_kernel_fp8.c` 和 `examples/fused-moe/fused_moe_kernel_fp8.h`


## 测试

使用 vllm

把 vllm/model_executor/layers/fused_moe/fused_moe.py 中 `fused_moe_kernel[grid](...)` 的调用去掉，改成

```python
        local_grid = (triton.cdiv(EM, config['BLOCK_SIZE_M']) * triton.cdiv(B.shape[1], config['BLOCK_SIZE_N']), 1, 1)
        
        import fused_moe_kernel_self_test
        fused_moe_kernel_self_test.fused_moe_kernel_fp8_constexpr_dispatcher(
            A,                          # a_ptr,
            B,                          # b_ptr,
            C,                          # c_ptr,
            A_scale,                    # a_scale_ptr,
            B_scale,                    # b_scale_ptr,
            topk_weights,               # topk_weights_ptr,
            sorted_token_ids,           # sorted_token_ids_ptr,
            expert_ids,                 # expert_ids_ptr,
            num_tokens_post_padded,     # num_tokens_post_padded_ptr,
            B.shape[1],                 # N,
            A.shape[1],                 # K,
            EM,                         # EM,
            topk_ids.numel(),           # num_valid_tokens,
            A.stride(0),                # stride_am,
            A.stride(1),                # stride_ak,
            B.stride(0),                # stride_be,
            B.stride(2),                # stride_bk,
            B.stride(1),                # stride_bn,
            C.stride(1),                # stride_cm,
            C.stride(2),                # stride_cn,
            A_scale.stride(0) if A_scale is not None and A_scale.ndim == 2 else 0, # stride_asm,
            A_scale.stride(1) if A_scale is not None and A_scale.ndim == 2 else 0, # stride_ask,
            B_scale.stride(0) if B_scale is not None and B_scale.ndim >= 2 else 0, # stride_bse,
            B_scale.stride(2) if B_scale is not None and B_scale.ndim == 3 else 0, # stride_bsk,
            B_scale.stride(1) if B_scale is not None and B_scale.ndim >= 2 else 0, # stride_bsn,
            0 if block_shape is None else block_shape[0],   # group_n
            0 if block_shape is None else block_shape[1],   # group_k
            config["BLOCK_SIZE_M"],
            config["BLOCK_SIZE_N"],
            config["BLOCK_SIZE_K"],
            config["GROUP_SIZE_M"],
            mul_routed_weight,
            top_k,
            # compute_type=compute_type,
            use_fp8_w8a8,
            use_int8_w8a16,
            config["num_warps"],
            config["num_stages"],
            local_grid[0],
            local_grid[1],
            local_grid[2],
        )
```

测试

```bash
pytest -s tests/kernels/test_block_fp8.py::test_w8a8_block_fp8_fused_moe
```

注意：请先不修改跑一遍，确保参数能跑得动，如果内存不足，请将下列参数 N_moe/K_moe/E 适当调小

另外，由于全量 kernel 较多，先设置 `M_moe = [7]` p跑对一个即可

```python
# M_moe = [1, 7, 83, 512, 2048]
M_moe = [7]
N_moe = [4608]  # [128, 4608, 13824]
K_moe = [7168]  # [256, 7168, 13824]
BLOCK_SIZE = [[128, 128]]
E = [256]  # [8, 24, 128, 256]
TOP_KS = [1]  # [1, 2, 6]
OUT_DTYPES = [torch.bfloat16]  # [torch.float32, torch.half, torch.bfloat16]
SEEDS = [0]

```