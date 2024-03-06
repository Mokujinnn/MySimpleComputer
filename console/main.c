#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "mySimpleComputer.h"

void
InitMem ()
{
  sc_memoryInit ();
  for (int i = 0; i < rand () % SIZEMEM; ++i)
    {
      sc_memorySet (i, rand () % 10000);
    }

  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
}

int
main ()
{
  int rows = 0;
  int cols = 0;

  if (!ttyname (STDOUT_FILENO))
    {
      printf ("Output stream is not a terminal\n");
      return 0;
    }

  mt_getscreensize (&rows, &cols);

  mt_clrscr ();
  if (!(90 < cols && 26 < rows))
    {
      printf ("Small terminal size\n");
      return 0;
    }

  InitMem ();

  for (int i = 0; i < SIZEMEM; ++i)
    {
      printCell (i, ForegroundDefault, BackgroundDefault);
    }
  printCell (55, ForegroundBlack, BackgroundLightGray);

  sc_accumulatorSet (1234);
  sc_icounterSet (2234);

  printFlags ();
  printDecodedCommand (12712);
  printAccumulator ();
  printCounters ();
  printCommand ();

  for (int i = 0; i < 7; i++)
    {
      printTerm (i, 0);
      getchar ();
    }

  mt_gotoXY (1, 20);

  return 0;
}
