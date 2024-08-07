#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "myBigChars.h"
#include "myTerm.h"

int
bc_box (int x1, int y1, int x2, int y2, enum colors box_fg, enum colors box_bg,
        char *header, enum colors header_fg, enum colors header_bg)
{
  int rows = 0;
  int cols = 0;
  int i = 0;
  int j = 0;
  int len = bc_strlen (header);
  int asclen = strlen (header);

  mt_getscreensize (&rows, &cols);

  if (y2 > rows || x2 > cols)
    {
      return -1;
    }

  mt_setbgcolor (box_bg);
  mt_setfgcolor (box_fg);
  mt_gotoXY (x1, y1);
  bc_printA (CHAR_ULC);

  i = x1 + 1;
  j = y1;
  while (i != x1 || j != y1)
    {
      if (i < x2 && j == y1)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_HOR_LINE);
          i++;
        }
      else if (i == x2 && j == y1)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_URC);
          j++;
        }
      else if (i == x2 && j < y2)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_VER_LINE);
          j++;
        }
      else if (i == x2 && j == y2)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_LRC);
          i--;
        }
      else if (i > x1 && j == y2)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_HOR_LINE);
          i--;
        }
      else if (i == x1 && j == y2)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_LLC);
          j--;
        }
      else if (i == x1 && j > y1)
        {
          mt_gotoXY (i, j);
          bc_printA (CHAR_VER_LINE);
          j--;
        }
    }

  mt_setbgcolor (header_bg);
  mt_setfgcolor (header_fg);

  if (asclen == len)
    {
      mt_gotoXY (x1 + 1 + ((x2 - x1) / 2) - (asclen + 1) / 2, y1);
    }
  else
    {
      mt_gotoXY (x1 + 1 + ((x2 - x1) / 2) - (len + 1) / 2, y1);
    }
  write (STDOUT_FILENO, header, asclen);

  mt_setdefaultcolor ();

  return 0;
}