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