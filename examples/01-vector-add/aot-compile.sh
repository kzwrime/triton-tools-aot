#!/bin/bash

# 开启回显，即打印执行的指令
set -x

# 有错误则退出
set -e

# 如果不存在 kernels 文件夹，则创建
if [ ! -d "./kernels" ]; then
    mkdir ./kernels
else
    rm ./kernels/* -rf
fi

python3 generate_kernel.py

python3 ../../tools/link.py ./kernels/*.h -o add_kernel

# ==================== 使用 Makefile 版本 ====================

# make clean
# make

# ===========================================================

# ==================== 使用 CMake 版本 =======================

if [ ! -d "./build" ]; then
    mkdir -p ./build
else
    rm build/* -rf
fi

cd build
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
make
cd ..

# ===========================================================

nvcc test_add_kernel.cu build/libadd_kernel_fp32.a -lcuda
