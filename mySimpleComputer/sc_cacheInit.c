#include "sc_variables.h"

void sc_cacheInit()
{
    for (int i = 0; i < CACHESIZE; i++)
    {
        CACHE[i].address = -1;
        CACHE[i].downtime = 0;
        for (int j = 0; j < 10; j++)
        {
            CACHE[i].line[j] = 0;
        }
    }
    IGNORE_CACHE = 0;
}