

extern "C" {
#include "fused_moe_kernel_fp8.h"
// #include "kernels/fused_moe_kernel_fp8/fused_moe_kernel_fp8.0860b04c2b25c33e4b2ae8317ea6cbd56d36aaeee2a3cc9d233fb26749410eb1_0d1d2d3d4d5d6d7d8d9d10d11d1213d14c15d16c17d18d19c20d21c22d23d24c.h"
}
#include <iostream>
#include <cuda.h>
#include <cuda_runtime.h>
#include <vector>
#include <typeinfo>


#define CUDA_CHECK(call) \
    do { \
        CUresult err = call; \
        if (err != CUDA_SUCCESS) { \
            const char *err_str; \
            cuGetErrorString(err, &err_str); \
            std::cerr << "CUDA error at " << __FILE__ << ":" << __LINE__ << " - " << err_str << std::endl; \
            exit(EXIT_FAILURE); \
        } \
    } while (0)

int main(){
    int n = 100;
    // Initialize CUDA
    std::cout << "Initializing CUDA..." << std::endl;
    CUDA_CHECK(cuInit(0));
    CUdevice device;
    CUDA_CHECK(cuDeviceGet(&device, 0));
    CUcontext context;
    CUDA_CHECK(cuCtxCreate(&context, 0, device));

    // CUdeviceptr d_vecA, d_vecB, d_vecC;
    // CUDA_CHECK(cuMemAlloc(&d_vecA, n * sizeof(float)));
    load_fused_moe_kernel_fp8();
    // unload_fused_moe_kernel_fp8();
    // load_fused_moe_kernel_fp8_0860b04c2b25c33e4b2ae8317ea6cbd56d36aaeee2a3cc9d233fb26749410eb1_0d1d2d3d4d5d6d7d8d9d10d11d1213d14c15d16c17d18d19c20d21c22d23d24c();

    CUresult result = fused_moe_kernel_fp8_constexpr_dispatcher_with_grid(
        cudaStreamPerThread,
        0x7ff388641e00,             // a_ptr = 
        0x7ff31e000000,             // b_ptr = 
        0x7ff388600000,             // c_ptr = 
        0x7ff388642200,             // a_scale_ptr = 
        0x7ff388631000,             // b_scale_ptr = 
        0x7ff38863fe00,             // topk_weights_ptr = 
        0x7ff388681800,             // sorted_token_ids_ptr = 
        0x7ff388641800,             // expert_ids_ptr = 
        0x7ff388641c00,             // num_tokens_post_padded_ptr = 
        7168,               // N = 
        128,                // K = 
        448,                // EM = 
        7,              // num_valid_tokens = 
        128,                // stride_am = 
        1,              // stride_ak = 
        917504,             // stride_be = 
        1,              // stride_bk = 
        128,                // stride_bn = 
        7168,               // stride_cm = 
        1,              // stride_cn = 
        1,              // stride_asm = 
        1,              // stride_ask = 
        56,             // stride_bse = 
        1,              // stride_bsk = 
        1,              // stride_bsn = 
        128,                // group_n = 
        128,                // group_k = 
        64,             // BLOCK_SIZE_M = 
        64,             // BLOCK_SIZE_N = 
        128,                // BLOCK_SIZE_K = 
        32,             // GROUP_SIZE_M = 
        1,              // MUL_ROUTED_WEIGHT = 
        1,              // top_k = 
        1,              // use_fp8_w8a8 = 
        0,              // use_int8_w8a16 = 
        4,              // num_warps = 
        3,              // num_stages = 
        784,                // gridx = 
        1,              // gridy = 
        1              // gridz = 
    );
    CUDA_CHECK(result);
}
