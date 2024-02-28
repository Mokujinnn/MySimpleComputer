#include <stdio.h>

int mt_clrscr ()
{
    printf("\E[H\E[2J");
}