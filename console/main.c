#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "mySimpleComputer.h"

void
InitMem ()
{
  for (int i = 0; i < rand () % SIZEMEM; ++i)
    {
      sc_memorySet (i, rand () % 10000);
    }
}

int
main ()
{
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

  InitMem();

  mt_clrscr();
  for (int i = 0; i < SIZEMEM; ++i)
  {
    printCell(i, BackgroundDefault, ForegroundDefault);
  }

  sc_accumulatorSet(1234);
  sc_icounterSet(2234);
  
  printFlags();
  printDecodedCommand(12712);
  printAccumulator();
  printCounters();

  mt_gotoXY(1, 20);

  return 0;
}
