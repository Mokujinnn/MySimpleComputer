#include "mySimpleComputer.h"

void printFlags()
{
    char str[10] = "P 0 M E T";

    for (int i = 0, k = 1; i < NUMBER_OF_FLAGS; ++i, k *= 2)
    {
        int value = -1;
        sc_regGet(k, &value);

        if (!value)
        {
            str[2*i] = '_';
        }
    }

    fwrite(str, 1, 10, stdout);
}