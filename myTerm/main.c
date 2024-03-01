#include <stdio.h>
#include <unistd.h>

#include "myTerm.h"

int main()
{
    mt_clrscr();
    mt_gotoXY(15, 2);
    mt_setbgcolor(DarkCyan);
    mt_setfgcolor(DarkRed);
    write (STDOUT_FILENO, "ASD", 4);
    
    mt_setdefaultcolor();
    mt_gotoXY(15, 3);
    write (STDOUT_FILENO, "ASD", 4);

    return 0;
}