#include <stdio.h>
#include "gpu.h"
#include "instruction.h"


int main(void)
{
    GPU gpu;
    gpu_init(&gpu);

    // printf("MicroGPU started!\n");
    // printf("  Registers: %d\n", GPU_REGISTER_COUNT);
    // printf("  Memory:    %d bytes\n", GPU_MEMORY_SIZE);
    // printf("  PC:        %u\n", gpu.pc);
    // printf("\n");

    // for (int i = 0; i < GPU_REGISTER_COUNT; i++) {
    //     printf("r%d: %u\n", i, gpu.registers[i]);
    // }

     Instruction instruction = {
        .opcode = MOV,
        .dest = 0,
        .src1 = 0,
        .src2 = 0,
        .immediate = 42
    };

    printf("MicroGPU started!\n");

    printf("Instruction opcode: %d\n", instruction.opcode);
    printf("Destination register: r%d\n", instruction.dest);
    printf("Immediate: %u\n", instruction.immediate);
    return 0;
}