#include "myTerm.h"
#include "myBigChars.h"

int bc_printbigchar (int bigchar[ARR_SIZE], int x, int y, enum colors fg, enum colors bg)
{
    int rows = 0;
    int cols = 0;

    mt_getscreensize(&rows, &cols);

    if (x + BITS_IN_BYTE > rows || x + BITS_IN_BYTE > cols || bigchar == NULL)
    {
        return -1;
    }

    mt_gotoXY(x, y);
    mt_setbgcolor(bg);
    mt_setfgcolor(fg);

    for (int i = 0; i < ARR_SIZE * sizeof(int); i++)
    {
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int flag = ((bigchar[i / 4]) >> ((i % 4) * BITS_IN_BYTE + j)) & 1;

            if (flag == 1)
            {
                mt_gotoXY(x + j, y + i);
                bc_printA(CHAR_BOX);
            }
            else
            {
                mt_gotoXY(x + j, y + i);
                bc_printA(" ");
            }
        }
    }
    mt_setdefaultcolor();
    return 0;
}