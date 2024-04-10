#include <stdio.h>
#include <unistd.h>

#include "myTerm.h"

int
mt_gotoXY (int x, int y)
{
  int rows;
  int cols;

  mt_getscreensize (&rows, &cols);
  if (x >= 0 && y >= 0 && x < cols && y < rows)
    {
      char tmp[25] = { 0 };
      snprintf (tmp, 25, "\E[%d;%dH", y, x);
      write (STDOUT_FILENO, tmp, 20);
      return 0;
    }

  return -1;
}