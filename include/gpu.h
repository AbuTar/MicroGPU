#ifndef GPU_H
#define GPU_H

#include <stdint.h>
#include <stdbool.h>
#include <types.h>

#define GPU_REGISTER_COUNT  8
#define GPU_MEMORY_SIZE 65536

typedef struct {
    u32 registers[GPU_REGISTER_COUNT];
    u8 memory[GPU_MEMORY_SIZE];
    u32 pc;
    bool halted;

}GPU;

void gpu_init(GPU *gpu);



#endif