#include "sc_variables.h"

int sc_getCacheLine(int linenum, int *mas)
{
    if (mas == NULL || linenum < 0 || linenum > 4)
    {
        return -1;
    }

    int line_size = CACHE[linenum].address == 120 ? 8 : 10;
    if (CACHE[linenum].address != -1)
    {
        for (int i = 0; i < line_size; i++)
        {
            mas[i] = CACHE[linenum].line[i];
        }
    }

    return CACHE[linenum].address;
}