#include <limits.h>
#include "sc_variables.h"

int sc_accumulatorSet(int value)
{
    if (value > INT_MAX && value < INT_MIN)
    {
        return -1;
    }
    
    ACC = value;
    return 0;
}