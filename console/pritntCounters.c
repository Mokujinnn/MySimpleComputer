#include "mySimpleComputer.h"

void printCounters()
{
    int value = 0;
    char str[10] = "IC: +";

    sc_icounterGet(&value);

    snprintf(&str[5], 5, "%.4x", value);
    fwrite(str, 1, 10, stdout);

}