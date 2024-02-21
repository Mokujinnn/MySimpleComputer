#include <limits.h>
#include "sc_variables.h"

int sc_icounterSet (int value)
{
    if (value > ULLONG_MAX || value < 0)
    {
        return -1;
    }
    
    INST_COUNTER = value;
    return 0;
}