#include <stdio.h>

#include "myTerm.h"

int mt_setbgcolor (enum colors color)
{
    printf("\E[%dm", Background + color);
    return 0;
}