#include "sc_variables.h"

int sc_regGet(int reg, int *value)
{
    if (!(reg >= 0 && reg < NUMBER_OF_FLAGS) || !value)
    {
        return -1;
    }

    *value = (REG_FLAG >> reg) & 1;

    return 0;
}