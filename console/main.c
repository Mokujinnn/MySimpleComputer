#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include "console.h"
#include "main.h"
#include "myBigChars.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"

int bigchars[18][2];

int
main ()
{
  int currentCell = 0;
  int escIsNotPresed = 1;
  enum keys key = -1;
  int interrupt = 0;
  int tc = 0;
  Init (*bigchars);

  mt_setcursorvisible (0);

  printAllBoxes ();
  printKeybord ();
  UpdateAndDraw (bigchars, currentCell);

  signal(SIGALRM, IRC);
  signal(SIGUSR1, IRC);

  struct itimerval nval, oval;

  nval.it_interval.tv_sec = 0;
  nval.it_interval.tv_usec = 500000;
  nval.it_value.tv_sec = 1;
  nval.it_value.tv_usec = 0;

  rk_mytermregime (0, 1, 1, 0, 0);

  setitimer (ITIMER_REAL, &nval, &oval);

  while (escIsNotPresed)
    {
      key = -1;
      interrupt = 0;

      sc_regGet(IGNORE_INTERRUPT, &interrupt);
      sc_tcounterGet(&tc);

      if (interrupt && tc == 0)
      {
        rk_readkey (&key);
      }
      Control (key, &currentCell, &escIsNotPresed);
    }

  rk_mytermregime (1, 1, 1, 1, 0);
  mt_setcursorvisible (1);
  mt_clrscr ();
  mt_gotoXY (1, 1);

  return 0;
}
