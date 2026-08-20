#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include <types.h>

// Represents the 10 Opcodes the GPU will use
typedef enum { 
    MOV,
    ADD,
    SUB,
    MULT,
    LD,
    STA,
    JMP,
    JZ,
    PRINT,
    HALT
} Opcode;

/*Need to be able to represent instructions like : 
    MOV   → dst + immediate
    ADD   → dst + src1 + src2
    PRINT → src1
    HALT  → nothing*/

typedef struct {
    Opcode opcode;

    u8 dest;
    u8 src1;
    u8 src2;

    u8 immediate;
} Instruction;

#endif