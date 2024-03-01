#include <stdio.h>

#include "myTerm.h"

int mt_setfgcolor (enum colors color)
{
    printf("\E[%dm", Foreground + color);
    return 0;
}