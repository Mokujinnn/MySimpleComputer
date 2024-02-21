#include "sc_variables.h"

int sc_regSet(int reg, int value)
{
    if (!(reg == OWERFLOW || reg == DIVISION_BY_ZERO || reg == OUTMEM || reg == WRONG_COMMAND || reg == IGNORE_INTERRUPT) 
        || value < 0 || value > 1)
    {
        return -1;
    }

    if (value)
    {
        REG_FLAG = REG_FLAG | reg;
    }
    else
    {
        REG_FLAG = REG_FLAG & ~reg;
    }

    return 0;
}