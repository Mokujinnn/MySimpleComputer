#include <stdio.h>
#include "myTerm.h"
#include "myBigChars.h"

int main(int argc, char const *argv[])
{
    mt_clrscr();
    bc_box(1, 1, 17, 10, ForegroundDarkCyan, BackgroundDefault, "allllll", ForegroundDarkRed, BackgroundBlack);
    mt_gotoXY(15, 15);
    return 0;
}