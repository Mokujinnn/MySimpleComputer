#include <stdio.h>
#include "myTerm.h"
#include "myBigChars.h"

int main(int argc, char const *argv[])
{
    mt_clrscr();
    bc_box(2, 2, 10, 10, ForegroundBlack, ForegroundBlack, "asd", ForegroundBlack, ForegroundBlack);
    mt_gotoXY(15, 15);
    return 0;
}