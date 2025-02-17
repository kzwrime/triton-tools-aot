import os,sys
import torch
import triton
import fused_moe

# # 获取当前文件的绝对路径
# current_dir = os.path.dirname(os.path.abspath(__file__))
# # 计算 ../../tools 的绝对路径
# tools_dir = os.path.abspath(os.path.join(current_dir, '../../'))
# # 将 tools 目录添加到 sys.path
# sys.path.append(tools_dir)
from tools.compile2 import kernel_to_c, FakeTensor
from itertools import product

# FP8_DTYPE = torch.float8_e4m3fnuz if current_platform.is_rocm() else torch.float8_e4m3fn
FP8_DTYPE = torch.float8_e4m3fn

int_eq_1 = 1
int_align_16 = 16
int_normal = 17

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
    "stride_asm": [int_align_16, int_eq_1, int_normal],   # 不好说 !
    "stride_ask": [int_align_16, int_eq_1],   # 不好说 !
    "stride_bse": [int_align_16, int_normal],   # 不好说 !
    "stride_bsk": [int_align_16, int_eq_1],   # 不好说 !
    "stride_bsn": [int_align_16, int_eq_1, int_normal],   # 不好说 !
    # Block size for block-wise quantization
    "group_n": [128],   # test_block_fp8 直接设成 128 即可
    "group_k": [128],   # test_block_fp8 直接设成 128 即可
    # "group_n": [0, 128],
    # "group_k": [0, 128],
    # Meta-parameters
    "BLOCK_SIZE_M": [64],
    "BLOCK_SIZE_N": [64],
    "BLOCK_SIZE_K": [128],  # test_block_fp8 直接设成 128 即可
    # "BLOCK_SIZE_K": [64, 128],
    # "GROUP_SIZE_M": [1, 32],
    "GROUP_SIZE_M": [32],   # test_block_fp8 直接设成 128 即可
    "MUL_ROUTED_WEIGHT": [0, 1],
    "top_k": [2, 1],
    "compute_type": [triton.language.bfloat16],
    "use_fp8_w8a8": [1],
    "use_int8_w8a16": [0],
    # "BLOCK_SIZE_M": [16, 32, 64, 128, 256],
    # "BLOCK_SIZE_N": [32, 64, 128, 256],
    # "BLOCK_SIZE_K": [64, 128, 256],
    # "GROUP_SIZE_M": [1, 16, 32, 64],
    # "MUL_ROUTED_WEIGHT": [0, 1],
    # "top_k": [1,2],
    # "compute_type": [triton.language.bfloat16],
    # "use_fp8_w8a8": [0, 1],
    # "use_int8_w8a16": [0, 1],
    "num_warps": [4, 8],
    # "num_stage": [2, 3, 4, 5],
    "num_stages": [3],
}

# print(func_args)

kernel_name="fused_moe_kernel"
kernel_output_name="fused_moe_kernel_fp8"
output_path_with_prefix="./kernels/fused_moe_kernel_fp8/fused_moe_kernel_fp8"
default_grid=(1024,1,1)

count = 0
keys, values = zip(*func_args.items())
for config_values in product(*values):
    config = dict(zip(keys, config_values))
    if config["MUL_ROUTED_WEIGHT"] == 0 and config["top_k"] != 1:
        continue
    
    # configs.append(config)
    print(f"count={count}, config={config}")
    ccinfo = fused_moe.fused_moe_kernel.warmup(grid=default_grid, **config)
    kernel_to_c(
        fused_moe.fused_moe_kernel,
        kernel_name,
        kernel_output_name,
        output_path_with_prefix,
        default_grid,
        ccinfo,
    )
    count += 1
    print()
    

# os.system('python test.py &')