#include "sc_variables.h"

int sc_tcounterGet(int *value)
{
    if (value == NULL)
    {
        return -1;
    }
    
    *value = TCOUNTER;
    return 0;
}