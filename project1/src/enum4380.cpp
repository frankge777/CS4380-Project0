#include "../include/enum4380.h"
#include <iostream>
#include <fstream>

using namespace std;

extern uint32_t reg_file[22];
extern uint8_t *prog_mem;
extern uint32_t cntrl_regs[5];
extern uint32_t data_regs[2];

enum RegNames {
    R0, R1, R2, R3, R4, R5, R6, R7, R8, R9, R10, R11, R12, R13, R14, R15,
    PC, SL, SB, SP, FP, HP
};

enum CntrlRegNames {
    OPERATION, OPERAND_1, OPERAND_2, OPERAND_3, IMMEDIATE
};

enum DataRegNames {
    REG_VAL_1, REG_VAL_2
};
bool fetch() {
    uint32_t pc = reg_file[PC];
    if (pc + 8 > 131072) { // Assuming mem_size is a global or accessible variable
        return false;
    }

    cntrl_regs[OPERATION] = prog_mem[pc];
    cntrl_regs[OPERAND_1] = prog_mem[pc + 1];
    cntrl_regs[OPERAND_2] = prog_mem[pc + 2];
    cntrl_regs[OPERAND_3] = prog_mem[pc + 3];
    cntrl_regs[IMMEDIATE] = *reinterpret_cast<uint32_t *>(&prog_mem[pc + 4]);

    reg_file[PC] += 8;
    return true;
}

bool decode() {
    uint32_t op = cntrl_regs[OPERATION];
    if (op >= 0 && op <= 31) { // Assuming op code range is 0-31
        data_regs[REG_VAL_1] = reg_file[cntrl_regs[OPERAND_1]];
        data_regs[REG_VAL_2] = reg_file[cntrl_regs[OPERAND_2]];
        return true;
    }
    return false;
}

bool execute() {
    uint32_t op = cntrl_regs[OPERATION];
    switch (op) {
        case 1: // JMP
            reg_file[PC] = cntrl_regs[IMMEDIATE];
            break;
        case 7: // MOV
            reg_file[cntrl_regs[OPERAND_1]] = data_regs[REG_VAL_1];
            break;
        case 18: // ADD
            reg_file[cntrl_regs[OPERAND_1]] = data_regs[REG_VAL_1] + data_regs[REG_VAL_2];
            break;
        case 31: // TRP
            if (cntrl_regs[IMMEDIATE] == 0) {
                return false; // TRP 0: Exit
            }
            break;
        default:
            return false;
    }
    return true;
}
