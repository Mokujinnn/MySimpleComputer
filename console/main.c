#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "main.h"
#include "myBigChars.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"

int
main ()
{
  int bigchars[18][2];
  int currentCell = 0;
  int escIsNotPresed = 1;
  Init (*bigchars);

  mt_setcursorvisible (0);

  printAllBoxes ();
  printKeybord ();

  rk_mytermregime (0, 1, 1, 0, 0);
  UpdateAll (bigchars, currentCell);

  while (escIsNotPresed)
    {
      enum keys key = -1;
      rk_readkey (&key);
      Control (key, &currentCell, &escIsNotPresed);
      UpdateAll (bigchars, currentCell);
    }

  mt_setcursorvisible (1);
  mt_clrscr ();
  mt_gotoXY (1, 1);

  return 0;
}
