#include <cuda.h>
#include <stdint.h>
#include <assert.h>

// launcher for: add_kernel_fp32_fp32_fp32_64_warps1xstages3
CUresult add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr);
CUresult add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_fp32_fp32_fp32_72020344_0d1d2d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_72020344_0d1d2d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_fp32_fp32_fp32_3688118c_0123c(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr);
CUresult add_kernel_fp32_fp32_fp32_3688118c_0123c_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_fp32_fp32_fp32_9969bdda_0123(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_9969bdda_0123_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);

CUresult add_kernel_fp32_fp32_fp32_64_warps1xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements == 1))
    return add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c(stream, x_ptr, y_ptr, output_ptr);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_fp32_fp32_fp32_72020344_0d1d2d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
  if ((n_elements == 1))
    return add_kernel_fp32_fp32_fp32_3688118c_0123c(stream, x_ptr, y_ptr, output_ptr);
if (1)
    return add_kernel_fp32_fp32_fp32_9969bdda_0123(stream, x_ptr, y_ptr, output_ptr, n_elements);

  return CUDA_ERROR_INVALID_VALUE;
}
CUresult add_kernel_fp32_fp32_fp32_64_warps1xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements == 1))
    return add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c_with_grid(stream, x_ptr, y_ptr, output_ptr, gridx, gridy, gridz);
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_fp32_fp32_fp32_72020344_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ((n_elements == 1))
    return add_kernel_fp32_fp32_fp32_3688118c_0123c_with_grid(stream, x_ptr, y_ptr, output_ptr, gridx, gridy, gridz);
if (1)
    return add_kernel_fp32_fp32_fp32_9969bdda_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);

  return CUDA_ERROR_INVALID_VALUE;
}

// load for: add_kernel_fp32_fp32_fp32_64_warps1xstages3
void load_add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c();
void load_add_kernel_fp32_fp32_fp32_72020344_0d1d2d3();
void load_add_kernel_fp32_fp32_fp32_3688118c_0123c();
void load_add_kernel_fp32_fp32_fp32_9969bdda_0123();
void load_add_kernel_fp32_fp32_fp32_64_warps1xstages3() {
  load_add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c();
  load_add_kernel_fp32_fp32_fp32_72020344_0d1d2d3();
  load_add_kernel_fp32_fp32_fp32_3688118c_0123c();
  load_add_kernel_fp32_fp32_fp32_9969bdda_0123();
}

// unload for: add_kernel_fp32_fp32_fp32_64_warps1xstages3
void unload_add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c();
void unload_add_kernel_fp32_fp32_fp32_72020344_0d1d2d3();
void unload_add_kernel_fp32_fp32_fp32_3688118c_0123c();
void unload_add_kernel_fp32_fp32_fp32_9969bdda_0123();
void unload_add_kernel_fp32_fp32_fp32_64_warps1xstages3() {
  unload_add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c();
  unload_add_kernel_fp32_fp32_fp32_72020344_0d1d2d3();
  unload_add_kernel_fp32_fp32_fp32_3688118c_0123c();
  unload_add_kernel_fp32_fp32_fp32_9969bdda_0123();
}

// launcher for: add_kernel_fp32_fp32_fp32_128_warps1xstages3
CUresult add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
CUresult add_kernel_fp32_fp32_fp32_ca04c8d9_0123(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_ca04c8d9_0123_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);

CUresult add_kernel_fp32_fp32_fp32_128_warps1xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3(stream, x_ptr, y_ptr, output_ptr, n_elements);
if (1)
    return add_kernel_fp32_fp32_fp32_ca04c8d9_0123(stream, x_ptr, y_ptr, output_ptr, n_elements);

  return CUDA_ERROR_INVALID_VALUE;
}
CUresult add_kernel_fp32_fp32_fp32_128_warps1xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  if ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0))
    return add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
if (1)
    return add_kernel_fp32_fp32_fp32_ca04c8d9_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);

  return CUDA_ERROR_INVALID_VALUE;
}

// load for: add_kernel_fp32_fp32_fp32_128_warps1xstages3
void load_add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3();
void load_add_kernel_fp32_fp32_fp32_ca04c8d9_0123();
void load_add_kernel_fp32_fp32_fp32_128_warps1xstages3() {
  load_add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3();
  load_add_kernel_fp32_fp32_fp32_ca04c8d9_0123();
}

// unload for: add_kernel_fp32_fp32_fp32_128_warps1xstages3
void unload_add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3();
void unload_add_kernel_fp32_fp32_fp32_ca04c8d9_0123();
void unload_add_kernel_fp32_fp32_fp32_128_warps1xstages3() {
  unload_add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3();
  unload_add_kernel_fp32_fp32_fp32_ca04c8d9_0123();
}

typedef CUresult (*kernel_func_t)(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
kernel_func_t add_kernel_fp32_fp32_fp32_kernels[] = {
  add_kernel_fp32_fp32_fp32_64_warps1xstages3,
  add_kernel_fp32_fp32_fp32_128_warps1xstages3,
};

typedef CUresult (*kernel_with_grid_func_t)(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
kernel_with_grid_func_t add_kernel_fp32_fp32_fp32_kernels_with_grid[] = {
  add_kernel_fp32_fp32_fp32_64_warps1xstages3_with_grid,
  add_kernel_fp32_fp32_fp32_128_warps1xstages3_with_grid,
};

int add_kernel_fp32_fp32_fp32_get_num_algos(void){
  return (int)(sizeof(add_kernel_fp32_fp32_fp32_kernels) / sizeof(add_kernel_fp32_fp32_fp32_kernels[0]));
}

CUresult add_kernel_fp32_fp32_fp32(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id){
  assert (algo_id < (int)sizeof(add_kernel_fp32_fp32_fp32_kernels));
  return add_kernel_fp32_fp32_fp32_kernels[algo_id](stream, x_ptr, y_ptr, output_ptr, n_elements);
}
CUresult add_kernel_fp32_fp32_fp32_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  assert (algo_id < (int)sizeof(add_kernel_fp32_fp32_fp32_kernels_with_grid));
  return add_kernel_fp32_fp32_fp32_kernels_with_grid[algo_id](stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
}

void load_add_kernel_fp32_fp32_fp32(void){
  load_add_kernel_fp32_fp32_fp32_64_warps1xstages3();
  load_add_kernel_fp32_fp32_fp32_128_warps1xstages3();
}

void unload_add_kernel_fp32_fp32_fp32(void){
  unload_add_kernel_fp32_fp32_fp32_64_warps1xstages3();
  unload_add_kernel_fp32_fp32_fp32_128_warps1xstages3();
}


CUresult add_kernel_fp32_fp32_fp32_constexpr_dispatcher_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int64_t BLOCK_SIZE, int num_warps, int num_stages, unsigned int gridx, unsigned int gridy, unsigned int gridz){
  if ( ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0) && (n_elements == 1)) && (BLOCK_SIZE == 64) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_1dc46967_0d1d2d3c_with_grid(stream, x_ptr, y_ptr, output_ptr, gridx, gridy, gridz);
  if ( ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0)) && (BLOCK_SIZE == 64) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_72020344_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ( ((x_ptr % 16 == 0) && (y_ptr % 16 == 0) && (output_ptr % 16 == 0)) && (BLOCK_SIZE == 128) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_264cd2df_0d1d2d3_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ( ((n_elements == 1)) && (BLOCK_SIZE == 64) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_3688118c_0123c_with_grid(stream, x_ptr, y_ptr, output_ptr, gridx, gridy, gridz);
  if ( (1) && (BLOCK_SIZE == 64) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_9969bdda_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);
  if ( (1) && (BLOCK_SIZE == 128) && (num_warps == 1) && (num_stages == 3) )
    return add_kernel_fp32_fp32_fp32_ca04c8d9_0123_with_grid(stream, x_ptr, y_ptr, output_ptr, n_elements, gridx, gridy, gridz);

  return CUDA_ERROR_INVALID_VALUE;
}

CUresult add_kernel_fp32_fp32_fp32_default(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements){
  return add_kernel_fp32_fp32_fp32(stream, x_ptr, y_ptr, output_ptr, n_elements, 0);
}
