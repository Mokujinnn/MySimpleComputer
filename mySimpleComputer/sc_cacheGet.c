#include "sc_variables.h"

int sc_cacheGet(int address, int *value)
{
    if (address < 0 || address >= SIZEMEM || value == NULL)
    {
        return -1;
    }

    int cacheline_address;

    for (int i = 0; i <CACHESIZE; i++)
        if (CACHE[i].address != -1)
            CACHE[i].downtime++;

    for (int i = 0; i < CACHESIZE; i++)
    {
        if (CACHE[i].address != -1)
        {
            cacheline_address = address - CACHE[i].address;
            if (cacheline_address >= 0 && cacheline_address < 10)
            {
                CACHE[i].downtime = 0;
                *value = CACHE[i].line[cacheline_address];
                return 0;
            }
        }
    }
    return -1;
}