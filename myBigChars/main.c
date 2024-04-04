#include <stdio.h>
#include "myTerm.h"
#include "myBigChars.h"

int main(int argc, char const *argv[])
{
    mt_clrscr();
    // bc_box(5, 5, 17, 10, ForegroundDarkCyan, BackgroundDefault, "allllll", ForegroundDarkRed, BackgroundBlack);
    int bigchar[2] = {0, 0};
    int value = -1;

    bc_setbigcharpos(bigchar, 5, 5, 1);
    bc_getbigcharpos(bigchar, 5, 5, &value);

    bc_printbigchar(bigchar, 1, 1, ForegroundDefault, BackgroundDefault);
    // int bigchar2[2] = {0xffc3c3ff, 0xffc0c0ff};
    // bc_printbigchar(bigchar2, 11, 2, ForegroundDarkGreen, BackgroundDefault);
    mt_gotoXY(15, 15);
    return 0;
}