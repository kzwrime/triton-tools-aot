#!/bin/bash

# 开启回显，即打印执行的指令
set -x

# 有错误则退出
set -e

# 如果不存在 kernels 文件夹，则创建
if [ ! -d "./kernels/fused_moe_kernel_fp8" ]; then
    mkdir -p ./kernels/fused_moe_kernel_fp8
else
    rm ./kernels/fused_moe_kernel_fp8/* -rf
fi

python3 generate_kernel.py > log.generate_kernel.txt
python3 ../../tools/link.py ./kernels/fused_moe_kernel_fp8/*.h -o fused_moe_kernel_fp8


if [ ! -d "./build" ]; then
    mkdir -p ./build
else
    rm build/* -rf
fi


cd build
cmake .. -DCMAKE_CUDA_ARCHITECTURES=90 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
make -j8
cd ..
python3 setup.py install
