#include <cuda.h>

CUresult add_kernel_fp32_fp32_fp32_64_warps1xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_64_warps1xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
void load_add_kernel_fp32_fp32_fp32_64_warps1xstages3();
void unload_add_kernel_fp32_fp32_fp32_64_warps1xstages3();
    

CUresult add_kernel_fp32_fp32_fp32_128_warps1xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32_128_warps1xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
void load_add_kernel_fp32_fp32_fp32_128_warps1xstages3();
void unload_add_kernel_fp32_fp32_fp32_128_warps1xstages3();
    
int add_kernel_fp32_fp32_fp32_get_num_algos(void);

CUresult add_kernel_fp32_fp32_fp32_default(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_fp32_fp32_fp32(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id);
void load_add_kernel_fp32_fp32_fp32();
void unload_add_kernel_fp32_fp32_fp32();
    
CUresult add_kernel_fp32_fp32_fp32_constexpr_dispatcher_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int64_t BLOCK_SIZE, int num_warps, int num_stages, unsigned int gridx, unsigned int gridy, unsigned int gridz);
