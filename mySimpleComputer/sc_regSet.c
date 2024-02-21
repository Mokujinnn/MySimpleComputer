#include "sc_variables.h"

int sc_regSet(int reg, int value)
{
    switch (reg)
    {
    case ON:
        REG_FLAG = value;
        return 0;
    
    default:
        return -1;
    }
}