#include <stdio.h>
#include "limits.h"

#include "sc_variables.h"

// FLAGS

void sc_regInit()
{
    REG_FLAG = 0;
}

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

// ACC

void sc_accumulatorInit()
{
    ACC = 0;
}

int sc_accumulatorSet(int value)
{
    if (value > INT_MAX && value < INT_MIN)
    {
        return -1;
    }
    
    ACC = value;
    return 0;
}

int sc_accumulatorGet(int * value)
{
    if (!value)
    {
        return -1;
    }

    *value = ACC;
    return 0;
}

// INST_COUNTER

void sc_icounterInit()
{
    INST_COUNTER = 0;
}

int sc_icounterSet (int value)
{
    if (value > ULLONG_MAX || value < 0)
    {
        return -1;
    }
    
    INST_COUNTER = value;
    return 0;
}

int sc_icounterGet (int * value)
{
    if (!value)
    {
        return -1;
    }
    
    *value = INST_COUNTER;
    return 0;
}