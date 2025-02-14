#!/bin/bash

# 开启回显，即打印执行的指令
set -x

# 有错误则退出
set -e

# 如果不存在 kernels 文件夹，则创建
if [ ! -d "./kernels" ]; then
    mkdir ./kernels
fi

compile_tools_path="../../tools/compile.py"
kernel_file_path="./01-vector-add.py"
kernel_name="add_kernel"
output_path_with_prefix="./kernels/add_kernel"
default_grid="1024,1,1"
kernel_output_name="add_kernel_fp32_fp32_fp32"

# 注意：同一组生成的 Kernel 不允许使用不同类型，暂时还不支持

# 执行 Python 脚本
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32, *fp32, *fp32, i32, 128"
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32, *fp32, *fp32, i32:1, 64"
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32, *fp32, *fp32, i32, 64"
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32:16, *fp32:16, *fp32:16, i32, 128"
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32:16, *fp32:16, *fp32:16, i32:1, 64"
python3 ${compile_tools_path} ${kernel_file_path} --kernel-name ${kernel_name} --out-name ${kernel_output_name} --out-path ${output_path_with_prefix} --grid ${default_grid} --signature "*fp32:16, *fp32:16, *fp32:16, i32, 64"
# python3 ../../tools/compile.py ./01-vector-add.py --kernel-name add_kernel --signature "*fp32:16, *fp32:16, *fp32:16, i32, 128" --out-path ./kernels/add_kernel --grid 1024,1,1
# python3 ../../tools/compile.py ./01-vector-add.py --kernel-name add_kernel --signature "*fp32:16, *fp32:16, *fp32:16, i32, 64" --out-path ./kernels/add_kernel --grid 1024,1,1
# python3 ../../tools/compile.py ./01-vector-add.py --kernel-name add_kernel --signature "*i32, *i32, *i32, i32:1, 64" --out-path ./kernels/add_kernel --grid 1024,1,1

python3 ../../tools/link.py ./kernels/*.h -o add_kernel
nvcc test_add_kernel.cu ./add_kernel.c ./kernels/*.c -lcuda