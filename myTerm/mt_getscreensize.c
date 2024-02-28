#include <stdio.h>
#include <sys/ioctl.h>
// #include <termios.h>
#include <unistd.h>

int mt_getscreensize (int * rows, int * cols)
{
    if (rows == NULL && cols == NULL)
    {
        return -1;
    }
    
    struct winsize ts;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &ts);

    printf("%d %d\n", ts.ws_col, ts.ws_row);
}