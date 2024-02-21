#include <stdio.h>
#include <stdlib.h>

#include "console.h"
#include "mySimpleComputer.h"

void
printMem ()
{
  for (int i = 0; i < rand () % SIZEMEM; ++i)
    {
      sc_memorySet (i, rand () % 10000);
    }

  for (int i = 0; i < SIZEMEM; ++i)
    {
      printCell (i);
      printf (" ");

      if ((i + 1) % 10 == 0)
        {
          printf ("\n");
        }
    }
  printf ("\n");
}

int
main ()
{
  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();

  printMem ();

  printf ("\n");
  if (sc_memorySet (100, 1000000) == -1)
    {
      printf ("Incorect value\n");
    }
  printf ("\n");

  sc_regSet (OWERFLOW, 1);
  sc_regSet (DIVISION_BY_ZERO, 0);
  sc_regSet (OUTMEM, 1);
  sc_regSet (WRONG_COMMAND, 0);
  sc_regSet (IGNORE_INTERRUPT, 1);

  printFlags ();
  printf ("\n");

  printf ("\n");
  if (sc_regSet (OUTMEM, 1000) == -1)
    {
      printf ("Incorect value\n");
    }
  printf ("\n");

  sc_accumulatorSet (1000);
  printAccumulator ();
  printf ("\n");

  printf ("\n");
  if (sc_accumulatorSet (1000000) == -1)
    {
      printf ("Incorect value\n");
    }
  printf ("\n");

  sc_icounterSet (1234);
  printCounters ();
  printf ("\n");

  printf ("\n");
  if (sc_icounterSet (-10) == -1)
    {
      printf ("Incorect value\n");
    }
  printf ("\n");

  int valuemem = 0;
  int valueacc = 0;

  sc_memoryGet (0, &valuemem);
  printDecodedCommand (valuemem);
  printf ("\n");

  sc_accumulatorGet (&valueacc);
  printDecodedCommand (valueacc);
  printf ("\n");

  sc_commandEncode (1, 99, 101, &valuemem);
  printDecodedCommand (valuemem);
  printf ("\n");

  return 0;
}
