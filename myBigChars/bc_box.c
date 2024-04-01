#include <stdio.h>
#include "myTerm.h"

int bc_box(int x1, int y1, int x2, int y2, enum colors box_fg,
enum colors box_bg, char *header, enum colors header_fg, enum colors header_bg)
{
    int rows = 0;
    int cols = 0;
    mt_getscreensize(&rows, &cols);

    if (!(rows >= y2 && cols >= x2))
    {
        return -1;
    }
    
    // char tmp[x2-x1] = {0};
    

    printf("%d %d\n", cols, rows);
}