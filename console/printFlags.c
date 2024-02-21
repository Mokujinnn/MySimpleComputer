#include "mySimpleComputer.h"

void printFlags()
{
    char str[10] = "P 0 M E T";

    for (int i = 0; i < NUMBER_OF_FLAGS; ++i)
    {
        int value = -1;
        sc_regGet(i, &value);

        if (!value)
        {
            str[2*i] = '_';
        }
    }

    fwrite(str, 1, 10, stdout);
}