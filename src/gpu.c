#include "gpu.h"

void gpu_init(GPU *gpu)
{
    // Initialies GPU
    for (int i = 0; i < GPU_REGISTER_COUNT; i++) {
        gpu->registers[i] = 0;
    }

    for (int i = 0; i < GPU_MEMORY_SIZE; i++) {
        gpu->memory[i] = 0;
    }
}