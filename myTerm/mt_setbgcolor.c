#include <stdio.h>
#include <unistd.h>

#include "myTerm.h"

int mt_setbgcolor (enum colors color)
{
    char tmp[10] = {0};
    snprintf(tmp, 10, "\E[%dm", color);
    write(STDOUT_FILENO, tmp, 10);
    return 0;
}