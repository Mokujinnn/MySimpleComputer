#include <stdio.h>
#include <unistd.h>

#include "myTerm.h"

int mt_setfgcolor (enum colors color)
{
    char tmp[10] = {0};
    snprintf(tmp, 10, "\E[%dm", Foreground + color);
    write(STDOUT_FILENO, tmp, 10);
    return 0;
}