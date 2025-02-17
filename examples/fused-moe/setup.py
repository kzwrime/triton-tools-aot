from setuptools import setup
from torch.utils.cpp_extension import BuildExtension, CUDAExtension

setup(
    name='fused_moe_kernel_self_test',
    ext_modules=[
        CUDAExtension(
            name='fused_moe_kernel_self_test',
            sources=['wrapper_for_torch.cu'],
            # libraries=['/usr/local/cuda/lib64/libcuda.so'],  # 链接CUDA库
            # library_dirs=['build'],
            extra_objects=[
                './build/libfused_moe_kernel_fp8.a',
            ],
            extra_compile_args={'cxx': [], 'nvcc': ['-O2']},
            extra_link_args=['-lcuda'],
        )
    ],
    cmdclass={
        'build_ext': BuildExtension
    }
)