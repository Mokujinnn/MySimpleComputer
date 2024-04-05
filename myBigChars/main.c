#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "myTerm.h"
#include "myBigChars.h"

int main(int argc, char const *argv[])
{
    mt_clrscr();
    // bc_box(5, 5, 17, 10, ForegroundDarkCyan, BackgroundDefault, "allllll", ForegroundDarkRed, BackgroundBlack);
    int bigchar[2] = {1000, 2222};

    int fd = open("file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0700);

    printf("%d\n", fd);

    bc_bigcharwrite(fd, bigchar, 1);

    close(fd);

    // bc_setbigcharpos(bigchar, 0, 0, 1);
    // bc_setbigcharpos(bigchar, 1, 1, 1);
    // bc_setbigcharpos(bigchar, 2, 2, 1);
    // bc_setbigcharpos(bigchar, 3, 3, 1);
    // bc_setbigcharpos(bigchar, 4, 4, 1);
    // bc_setbigcharpos(bigchar, 5, 5, 1);
    // bc_setbigcharpos(bigchar, 6, 6, 1);
    // bc_setbigcharpos(bigchar, 7, 7, 1);
    // bc_setbigcharpos(bigchar, 0, 7, 1);
    // bc_setbigcharpos(bigchar, 1, 6, 1);
    // bc_setbigcharpos(bigchar, 2, 5, 1);
    // bc_setbigcharpos(bigchar, 3, 4, 1);
    // bc_setbigcharpos(bigchar, 4, 3, 1);
    // bc_setbigcharpos(bigchar, 5, 2, 1);
    // bc_setbigcharpos(bigchar, 6, 1, 1);
    // bc_setbigcharpos(bigchar, 7, 0, 1);

    // bc_printbigchar(bigchar, 1, 1, ForegroundDefault, BackgroundDefault);
    // int bigchar2[2] = {0xffc3c3ff, 0xffc0c0ff};
    // bc_printbigchar(bigchar2, 11, 2, ForegroundDarkGreen, BackgroundDefault);
    mt_gotoXY(15, 15);
    return 0;
}