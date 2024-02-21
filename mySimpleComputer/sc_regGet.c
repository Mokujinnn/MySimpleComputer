#include "sc_variables.h"

int sc_regGet(int reg, int *value)
{
    switch (reg)
    {
    case ON:
        *value = REG_FLAG;
        return 0;
    
    default:
        return -1;
    }
}