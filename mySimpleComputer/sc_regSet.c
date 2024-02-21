#include "sc_variables.h"

int sc_regSet(int reg, int value)
{
    if (!(reg >= 0 && reg < NUMBER_OF_FLAGS) || value < 0 || value > 1)
    {
        return -1;
    }

    if (value)
    {
        REG_FLAG = REG_FLAG | (1 << reg);
    }
    else
    {
        REG_FLAG = REG_FLAG & ~(1 << reg);
    }
    
    return 0;
}