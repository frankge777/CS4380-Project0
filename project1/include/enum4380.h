#ifndef EMU4380_H
#define EMU4380_H

#include <cstdint>

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

#endif