#include <stdio.h>
#include "myTerm.h"
#include "myBigChars.h"

int main(int argc, char const *argv[])
{
    mt_clrscr();
    // bc_box(5, 5, 17, 10, ForegroundDarkCyan, BackgroundDefault, "allllll", ForegroundDarkRed, BackgroundBlack);
    int bigchar1[2] = {0xff0303ff, 0xffc3c3ff};
    bc_printbigchar(bigchar1, 2, 2, ForegroundDarkRed, BackgroundDefault);
    int bigchar2[2] = {0xffc3c3ff, 0xffc0c0ff};
    bc_printbigchar(bigchar2, 11, 2, ForegroundDarkGreen, BackgroundDefault);
    mt_gotoXY(15, 15);
    return 0;
}