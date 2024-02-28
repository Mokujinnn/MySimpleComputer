#include <stdio.h>

int mt_clrscr();
int mt_getscreensize (int * rows, int * cols);


int main()
{
    // mt_clrscr();
    int x, y;
    mt_getscreensize(x, y);
    return 0;
}