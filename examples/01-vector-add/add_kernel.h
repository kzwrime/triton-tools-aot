#include <cuda.h>
#ifdef __cplusplus
extern "C"{
#endif // __cplusplus

CUresult add_kernel_128_warps4xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_128_warps4xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
void load_add_kernel_128_warps4xstages3();
void unload_add_kernel_128_warps4xstages3();
    

CUresult add_kernel_64_warps4xstages3(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel_64_warps4xstages3_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, unsigned int gridx, unsigned int gridy, unsigned int gridz);
void load_add_kernel_64_warps4xstages3();
void unload_add_kernel_64_warps4xstages3();
    
int add_kernel_get_num_algos(void);

CUresult add_kernel_default(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements);
CUresult add_kernel(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int algo_id);
void load_add_kernel();
void unload_add_kernel();
    
CUresult add_kernel_constexpr_dispatcher_with_grid(CUstream stream, CUdeviceptr x_ptr, CUdeviceptr y_ptr, CUdeviceptr output_ptr, int32_t n_elements, int64_t BLOCK_SIZE, int num_warps, int num_stages, unsigned int gridx, unsigned int gridy, unsigned int gridz);
#ifdef __cplusplus
}
#endif // __cplusplus
