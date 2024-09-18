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
    uint32_t rd, rs, rs1, rs2, imm, addr;

    switch (op) {
        case 7: // MOV
            rd = cntrl_regs[OPERAND_1];
            rs = cntrl_regs[OPERAND_2];
            reg_file[rd] = reg_file[rs];
            break;

        case 8: // MOVI
            rd = cntrl_regs[OPERAND_1];
            imm = cntrl_regs[IMMEDIATE];
            reg_file[rd] = imm;
            break;

        case 9: // LDA
            rd = cntrl_regs[OPERAND_1];
            addr = cntrl_regs[IMMEDIATE];
            reg_file[rd] = addr;
            break;

        case 10: // STR
            rs = cntrl_regs[OPERAND_1];
            addr = cntrl_regs[IMMEDIATE];
            *reinterpret_cast<uint32_t *>(&prog_mem[addr]) = reg_file[rs];
            break;

        case 11: // LDR
            rd = cntrl_regs[OPERAND_1];
            addr = cntrl_regs[IMMEDIATE];
            reg_file[rd] = *reinterpret_cast<uint32_t *>(&prog_mem[addr]);
            break;

        case 12: // STB
            rs = cntrl_regs[OPERAND_1];
            addr = cntrl_regs[IMMEDIATE];
            prog_mem[addr] = static_cast<unsigned char>(reg_file[rs] & 0xFF);
            break;

        case 13: // LDB
            rd = cntrl_regs[OPERAND_1];
            addr = cntrl_regs[IMMEDIATE];
            reg_file[rd] = static_cast<uint32_t>(prog_mem[addr]);
            break;

        case 18: // ADD
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            rs2 = cntrl_regs[OPERAND_3];
            reg_file[rd] = reg_file[rs1] + reg_file[rs2];
            break;

        case 19: // ADDI
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            imm = cntrl_regs[IMMEDIATE];
            reg_file[rd] = reg_file[rs1] + imm;
            break;

        case 20: // SUB
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            rs2 = cntrl_regs[OPERAND_3];
            reg_file[rd] = reg_file[rs1] - reg_file[rs2];
            break;

        case 21: // SUBI
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            imm = cntrl_regs[IMMEDIATE];
            reg_file[rd] = reg_file[rs1] - imm;
            break;

        case 22: // MUL
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            rs2 = cntrl_regs[OPERAND_3];
            reg_file[rd] = reg_file[rs1] * reg_file[rs2];
            break;

        case 23: // MULI
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            imm = cntrl_regs[IMMEDIATE];
            reg_file[rd] = reg_file[rs1] * imm;
            break;

        case 24: // DIV
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            rs2 = cntrl_regs[OPERAND_3];
            if (reg_file[rs2] == 0) {
                std::cerr << "Division by zero error\n";
                return false;
            }
            reg_file[rd] = reg_file[rs1] / reg_file[rs2];
            break;

        case 25: // SDIV
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            rs2 = cntrl_regs[OPERAND_3];
            if (reg_file[rs2] == 0) {
                std::cerr << "Division by zero error\n";
                return false;
            }
            reg_file[rd] = static_cast<int32_t>(reg_file[rs1]) / static_cast<int32_t>(reg_file[rs2]);
            break;

        case 26: // DIVI
            rd = cntrl_regs[OPERAND_1];
            rs1 = cntrl_regs[OPERAND_2];
            imm = cntrl_regs[IMMEDIATE];
            if (imm == 0) {
                std::cerr << "Division by zero error\n";
                return false;
            }
            reg_file[rd] = static_cast<int32_t>(reg_file[rs1]) / static_cast<int32_t>(imm);
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
