#include <stdio.h>

#include "myTerm.h"

int mt_gotoXY (int x, int y)
{
    int rows;
    int cols;

    mt_getscreensize(&rows, &cols);
    if (x >= 0 && y >= 0 && x < cols && y < rows)
    {
        printf("\E[%d;%dH", y, x);
        return 0;
    }

    return -1;  
}