#include <torch/extension.h>
#include <cuda_runtime.h>
#include <vector>
#include <iostream>

#include "fused_moe_kernel_fp8.h"

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

// 封装函数
void fused_moe_kernel_fp8_constexpr_dispatcher(
    const torch::Tensor& a,           // torch.float8_e4m3fn
    const torch::Tensor& b,           // torch.float8_e4m3fn
    const torch::Tensor& c,           // torch.bfloat16
    const torch::Tensor& a_scale,     // torch.float32
    const torch::Tensor& b_scale,     // torch.float32
    const torch::Tensor& topk_weights,// torch.float32
    const torch::Tensor& sorted_token_ids, // torch.int32
    const torch::Tensor& expert_ids,  // torch.int32
    const torch::Tensor& num_tokens_post_padded, // torch.int32
    int32_t N, int32_t K, int32_t EM, int32_t num_valid_tokens,
    int32_t stride_am, int32_t stride_ak, int32_t stride_be, int32_t stride_bk,
    int32_t stride_bn, int32_t stride_cm, int32_t stride_cn,
    int32_t stride_asm, int32_t stride_ask, int32_t stride_bse,
    int32_t stride_bsk, int32_t stride_bsn,
    int64_t group_n, int64_t group_k, int64_t BLOCK_SIZE_M,
    int64_t BLOCK_SIZE_N, int64_t BLOCK_SIZE_K, int64_t GROUP_SIZE_M,
    int64_t MUL_ROUTED_WEIGHT, int64_t top_k, int64_t use_fp8_w8a8,
    int64_t use_int8_w8a16, int num_warps, int num_stages,
    unsigned int gridx, unsigned int gridy, unsigned int gridz
) {



    // 检查输入张量是否在CUDA设备上
    TORCH_CHECK(a.is_cuda(), "Input tensor 'a' must be on CUDA device");
    TORCH_CHECK(b.is_cuda(), "Input tensor 'b' must be on CUDA device");
    TORCH_CHECK(c.is_cuda(), "Input tensor 'c' must be on CUDA device");
    TORCH_CHECK(a_scale.is_cuda(), "Input tensor 'a_scale' must be on CUDA device");
    TORCH_CHECK(b_scale.is_cuda(), "Input tensor 'b_scale' must be on CUDA device");
    TORCH_CHECK(topk_weights.is_cuda(), "Input tensor 'topk_weights' must be on CUDA device");
    TORCH_CHECK(sorted_token_ids.is_cuda(), "Input tensor 'sorted_token_ids' must be on CUDA device");
    TORCH_CHECK(expert_ids.is_cuda(), "Input tensor 'expert_ids' must be on CUDA device");
    TORCH_CHECK(num_tokens_post_padded.is_cuda(), "Input tensor 'num_tokens_post_padded' must be on CUDA device");

    // 获取张量的设备指针
    CUdeviceptr a_ptr = reinterpret_cast<CUdeviceptr>(a.data_ptr());
    CUdeviceptr b_ptr = reinterpret_cast<CUdeviceptr>(b.data_ptr());
    CUdeviceptr c_ptr = reinterpret_cast<CUdeviceptr>(c.data_ptr());
    CUdeviceptr a_scale_ptr = reinterpret_cast<CUdeviceptr>(a_scale.data_ptr());
    CUdeviceptr b_scale_ptr = reinterpret_cast<CUdeviceptr>(b_scale.data_ptr());
    CUdeviceptr topk_weights_ptr = reinterpret_cast<CUdeviceptr>(topk_weights.data_ptr());
    CUdeviceptr sorted_token_ids_ptr = reinterpret_cast<CUdeviceptr>(sorted_token_ids.data_ptr());
    CUdeviceptr expert_ids_ptr = reinterpret_cast<CUdeviceptr>(expert_ids.data_ptr());
    CUdeviceptr num_tokens_post_padded_ptr = reinterpret_cast<CUdeviceptr>(num_tokens_post_padded.data_ptr());

    printf("a_ptr = %p\n", a_ptr);
    printf("b_ptr = %p\n", b_ptr);
    printf("c_ptr = %p\n", c_ptr);
    printf("a_scale_ptr = %p\n", a_scale_ptr);
    printf("b_scale_ptr = %p\n", b_scale_ptr);
    printf("topk_weights_ptr = %p\n", topk_weights_ptr);
    printf("sorted_token_ids_ptr = %p\n", sorted_token_ids_ptr);
    printf("expert_ids_ptr = %p\n", expert_ids_ptr);
    printf("num_tokens_post_padded_ptr = %p\n", num_tokens_post_padded_ptr);

    std::cout << "N = " << N << '\n';
    std::cout << "K = " << K << '\n';
    std::cout << "EM = " << EM << '\n';
    std::cout << "num_valid_tokens = " << num_valid_tokens << '\n';
    std::cout << "stride_am = " << stride_am << '\n';
    std::cout << "stride_ak = " << stride_ak << '\n';
    std::cout << "stride_be = " << stride_be << '\n';
    std::cout << "stride_bk = " << stride_bk << '\n';
    std::cout << "stride_bn = " << stride_bn << '\n';
    std::cout << "stride_cm = " << stride_cm << '\n';
    std::cout << "stride_cn = " << stride_cn << '\n';
    std::cout << "stride_asm = " << stride_asm << '\n';
    std::cout << "stride_ask = " << stride_ask << '\n';
    std::cout << "stride_bse = " << stride_bse << '\n';
    std::cout << "stride_bsk = " << stride_bsk << '\n';
    std::cout << "stride_bsn = " << stride_bsn << '\n';
    std::cout << "group_n = " << group_n << '\n';
    std::cout << "group_k = " << group_k << '\n';
    std::cout << "BLOCK_SIZE_M = " << BLOCK_SIZE_M << '\n';
    std::cout << "BLOCK_SIZE_N = " << BLOCK_SIZE_N << '\n';
    std::cout << "BLOCK_SIZE_K = " << BLOCK_SIZE_K << '\n';
    std::cout << "GROUP_SIZE_M = " << GROUP_SIZE_M << '\n';
    std::cout << "MUL_ROUTED_WEIGHT = " << MUL_ROUTED_WEIGHT << '\n';
    std::cout << "top_k = " << top_k << '\n';
    std::cout << "use_fp8_w8a8 = " << use_fp8_w8a8 << '\n';
    std::cout << "use_int8_w8a16 = " << use_int8_w8a16 << '\n';
    std::cout << "num_warps = " << num_warps << '\n';
    std::cout << "num_stages = " << num_stages << '\n';
    std::cout << "gridx = " << gridx << '\n';
    std::cout << "gridy = " << gridy << '\n';
    std::cout << "gridz = " << gridz << '\n';

    // 调用原始CUDA函数
    CUresult result = fused_moe_kernel_fp8_constexpr_dispatcher_with_grid(
        cudaStreamPerThread,
        a_ptr, b_ptr, c_ptr, a_scale_ptr, b_scale_ptr, topk_weights_ptr,
        sorted_token_ids_ptr, expert_ids_ptr, num_tokens_post_padded_ptr,
        N, K, EM, num_valid_tokens, stride_am, stride_ak, stride_be, stride_bk,
        stride_bn, stride_cm, stride_cn, stride_asm, stride_ask, stride_bse,
        stride_bsk, stride_bsn, group_n, group_k, BLOCK_SIZE_M, BLOCK_SIZE_N,
        BLOCK_SIZE_K, GROUP_SIZE_M, MUL_ROUTED_WEIGHT, top_k, use_fp8_w8a8,
        use_int8_w8a16, num_warps, num_stages, gridx, gridy, gridz
    );
    CUDA_CHECK(result);

    // 检查CUDA函数调用是否成功
    if (result != CUDA_SUCCESS) {
        throw std::runtime_error("CUDA kernel launch failed");
    }
}

// 绑定到Python模块
PYBIND11_MODULE(TORCH_EXTENSION_NAME, m) {
    m.def("fused_moe_kernel_fp8_constexpr_dispatcher", &fused_moe_kernel_fp8_constexpr_dispatcher, "Fused MoE Kernel FP8 Dispatcher");
}