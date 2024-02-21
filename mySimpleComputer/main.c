#include <stdio.h>

#include "mySimpleComputer.h"
// #include "sc_variables.h"

void printCell(int address)
{

}

int main()
{
    sc_regInit();

    sc_regSet(OWERFLOW, 1);
    sc_regSet(OUTMEM, 1); 
    sc_regSet(IGNORE_INTERRUPT, 0);

    int mas[5] = {0};

    for (int i = 0; i < 5; ++i)
    {
        sc_regGet(i, mas+i);
    }
    
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", mas[i]);
    }

}