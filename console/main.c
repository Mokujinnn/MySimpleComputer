#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "mySimpleComputer.h"
#include "myBigChars.h"

void InitMem()
{
  sc_memoryInit();
  for (int i = 0; i < rand() % SIZEMEM; ++i)
  {
    sc_memorySet(i, rand() % 10000);
  }

  sc_regInit();
  sc_accumulatorInit();
  sc_icounterInit();
}

int CheckOutputStream()
{
  int rows = 0;
  int cols = 0;

  if (!ttyname(STDOUT_FILENO))
  {
    printf("Output stream is not a terminal\n");
    return 0;
  }

  mt_getscreensize(&rows, &cols);

  mt_clrscr();
  if (!(90 < cols && 26 < rows))
  {
    printf("Small terminal size\n");
    return 0;
  }
  return 1;
}

void Init()
{
  InitMem();
  int status = CheckOutputStream();

  if (!status)
  {
    exit(EXIT_FAILURE);
  }
}

void printMem()
{
  bc_box(1, 1, 61, 15, ForegroundDefault, BackgroundDefault, "Memory", ForegroundDarkRed, ForegroundDefault);

  for (int i = 0; i < SIZEMEM; ++i)
  {
    printCell(i, ForegroundDefault, BackgroundDefault);
  }
  printCell(55, ForegroundBlack, BackgroundLightGray);
}

int main()
{
  int bigchars[18][2];

  Init();

  printMem();

  sc_accumulatorSet(1234);
  sc_icounterSet(2234);

  printFlags();
  printDecodedCommand(12712);
  printAccumulator();
  printCounters();
  printCommand();

  for (int i = 0; i < 7; i++)
  {
    printTerm(i, 0);
    getchar();
  }

  mt_gotoXY(1, 28);

  return 0;
}