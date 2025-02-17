#include <cuda.h>
#include <stdint.h>
#include <assert.h>
#include <stdio.h>

// launcher for: add_kernel_128_warps4xstages3
CUresult add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);

CUresult add_kernel_128_warps4xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0))
    return add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((output_ptr % 16 == 0))
    return add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((n_elements % 16 == 0))
    return add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d(stream, x_ptr, y_ptr, output_ptr, n_elements);
if (1)
    return add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123(stream, x_ptr, y_ptr, output_ptr, n_elements);

  return CUDA_ERROR_INVALID_VALUE;
}
CUresult add_kernel_128_warps4xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0))
    return add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((output_ptr % 16 == 0))
    return add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((n_elements % 16 == 0))
    return add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
if (1)
    return add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);

  return CUDA_ERROR_INVALID_VALUE;
}

// load for: add_kernel_128_warps4xstages3
void load_add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d();
void load_add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3();
void load_add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d();
void load_add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d();
void load_add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23();
void load_add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3();
void load_add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d();
void load_add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123();
void load_add_kernel_128_warps4xstages3() {
  load_add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d();
  load_add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3();
  load_add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d();
  load_add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d();
  load_add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23();
  load_add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3();
  load_add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d();
  load_add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123();
}

// unload for: add_kernel_128_warps4xstages3
void unload_add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d();
void unload_add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3();
void unload_add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d();
void unload_add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d();
void unload_add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23();
void unload_add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3();
void unload_add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d();
void unload_add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123();
void unload_add_kernel_128_warps4xstages3() {
  unload_add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d();
  unload_add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3();
  unload_add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d();
  unload_add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d();
  unload_add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23();
  unload_add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3();
  unload_add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d();
  unload_add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123();
}

// launcher for: add_kernel_64_warps4xstages3
CUresult add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);

CUresult add_kernel_64_warps4xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0))
    return add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((n_elements % 16 == 0))
    return add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((output_ptr % 16 == 0))
    return add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
if (1)
    return add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123(stream, x_ptr, y_ptr, output_ptr, n_elements);

  return CUDA_ERROR_INVALID_VALUE;
}
CUresult add_kernel_64_warps4xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((output_ptr % 16 == 0) && (n_elements % 16 == 0))
    return add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0))
    return add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((n_elements % 16 == 0))
    return add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((output_ptr % 16 == 0))
    return add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
if (1)
    return add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);

  return CUDA_ERROR_INVALID_VALUE;
}

// load for: add_kernel_64_warps4xstages3
void load_add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d();
void load_add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3();
void load_add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d();
void load_add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d();
void load_add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23();
void load_add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d();
void load_add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3();
void load_add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123();
void load_add_kernel_64_warps4xstages3() {
  load_add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d();
  load_add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3();
  load_add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d();
  load_add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d();
  load_add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23();
  load_add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d();
  load_add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3();
  load_add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123();
}

// unload for: add_kernel_64_warps4xstages3
void unload_add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d();
void unload_add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3();
void unload_add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d();
void unload_add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d();
void unload_add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23();
void unload_add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d();
void unload_add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3();
void unload_add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123();
void unload_add_kernel_64_warps4xstages3() {
  unload_add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d();
  unload_add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3();
  unload_add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d();
  unload_add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d();
  unload_add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23();
  unload_add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d();
  unload_add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3();
  unload_add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123();
}

typedef CUresult (*kernel_func_t)(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
kernel_func_t add_kernel_kernels[] = {
  add_kernel_128_warps4xstages3,
  add_kernel_64_warps4xstages3,
};

typedef CUresult (*kernel_with_grid_func_t)(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
kernel_with_grid_func_t add_kernel_kernels_with_grid[] = {
  add_kernel_128_warps4xstages3_with_grid,
  add_kernel_64_warps4xstages3_with_grid,
};

int add_kernel_get_num_algos(void){
  return (int)(sizeof(add_kernel_kernels) / sizeof(add_kernel_kernels[0]));
}

CUresult add_kernel(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id){
  assert (algo_id < (int)sizeof(add_kernel_kernels));
  return add_kernel_kernels[algo_id](stream, x_ptr, y_ptr, output_ptr, n_elements);
}
CUresult add_kernel_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  assert (algo_id < (int)sizeof(add_kernel_kernels_with_grid));
  return add_kernel_kernels_with_grid[algo_id](stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
}

void load_add_kernel(void){
  load_add_kernel_128_warps4xstages3();
  load_add_kernel_64_warps4xstages3();
}

void unload_add_kernel(void){
  unload_add_kernel_128_warps4xstages3();
  unload_add_kernel_64_warps4xstages3();
}


CUresult add_kernel_constexpr_dispatcher_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int64_t BLOCK_SIZE, int num_warps, int num_stages, unsigned int gridx, unsigned int gridy, unsigned int gridz){
if ((num_warps == 4)){
  if ((num_stages == 3)){
    if ((x_ptr % 16 == 0)){
      if ((y_ptr % 16 == 0)){
        if ((output_ptr % 16 == 0)){
          if ((n_elements % 16 == 0)){
            if ((BLOCK_SIZE == 64)){
              return add_kernel_73d8a6bfe4d07ff9342f14cf5956d80f381b17e9a9372a3c4538ea402511acc4_0d1d2d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_dd66c8cb6d32ecaa588e5044e9329a1a4bbdf8a45262e8979defd334ccf65108_0d1d2d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          } // if ((n_elements % 16 == 0))
          else {
            if ((BLOCK_SIZE == 64)){
              return add_kernel_3c0d9322bc9ed6cf474419bc00968a56b21b639a35b06dc17564c00df6dfe916_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_a4cdea5e00e0f438d925262e97136b6bfd0d6ec3403f4af47eef731d32e43710_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          }
        } // if ((output_ptr % 16 == 0))
        else {
          if ((n_elements % 16 == 0)){
            if ((BLOCK_SIZE == 64)){
              return add_kernel_dfaf48a1bfd727bd1f5ddacba876caa9736ba88d1ffcdaae0969c1b17bffedca_0d1d23d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_e5c966faf62d399e21a34f73c02f79c5007cf9617dd9ed0b8aed54a1090cf30c_0d1d23d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          } // if ((n_elements % 16 == 0))
          else {
            if ((BLOCK_SIZE == 64)){
              return add_kernel_d285a67fc00d66c5b8253c669a4a889d6f3b7c26f30c674015e4a96fbce18962_0d1d23_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_d526832e3d098404792c5c08e65381c090ebbd9570efcb5053968e6c1b49bce9_0d1d23_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          }
        }
      } // if ((y_ptr % 16 == 0))
      else {
        printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
      }
    } // if ((x_ptr % 16 == 0))
    else {
      if ((y_ptr % 16 == 0)){
        printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
      } // if ((y_ptr % 16 == 0))
      else {
        if ((output_ptr % 16 == 0)){
          if ((n_elements % 16 == 0)){
            if ((BLOCK_SIZE == 64)){
              return add_kernel_ce56e107cb3cd8d7b208d21c85aca6a4d5b5a0e4334941ac5f10a81a9143220b_012d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_c5c3d48b0dbfb649dc0ba6e3d8ba9006f47df7cef2263620cb066b1c335744c4_012d3d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          } // if ((n_elements % 16 == 0))
          else {
            if ((BLOCK_SIZE == 64)){
              return add_kernel_594d1627befdfab9473038f0d0931a47b573eca05dac404893f47e5df6301840_012d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_08b4e94c504508fd287c1101f044c5f72db270276b2c71e32fa319e02da503fd_012d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          }
        } // if ((output_ptr % 16 == 0))
        else {
          if ((n_elements % 16 == 0)){
            if ((BLOCK_SIZE == 64)){
              return add_kernel_10b32d89dd6f149e66c56fa49b3c5bf02b7cda8d05ca80d0f0cecf13639c13c2_0123d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_955eb290527ac4c6e8ddf4b89dd527b2b9835d926dec34b8847b5d87513659ec_0123d_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          } // if ((n_elements % 16 == 0))
          else {
            if ((BLOCK_SIZE == 64)){
              return add_kernel_77e58d6ed14be16527a4e464a74752f16d44ed69c72da8097286377d8a1944d9_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // if ((BLOCK_SIZE == 64))
            else if ((BLOCK_SIZE == 128)){
              return add_kernel_27044668cadbf30d0323325a18b3079bc6327a54fe28c593fa0c73605a367806_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
            } // else if ((BLOCK_SIZE == 128))
            else {
              printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
            }
          }
        }
      }
    }
  } // if ((num_stages == 3))
  else {
    printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
  }
} // if ((num_warps == 4))
else {
  printf("%s:%d No Arguement Matched !\n", __FILE__, __LINE__);
}

  return CUDA_ERROR_INVALID_VALUE;
}

CUresult add_kernel_default(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  return add_kernel(stream, x_ptr, y_ptr, output_ptr, n_elements, 0);
}
