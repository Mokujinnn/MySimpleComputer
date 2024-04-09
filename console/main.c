#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "mySimpleComputer.h"
#include "myBigChars.h"

void loadFont(int * bigchar, int n)
{
  FILE * f = fopen("font/font.bin", "rb");

  if (f == NULL)
  {
    printf("Cant open file with font\n");
    exit(EXIT_FAILURE);
  }
  
  fread(bigchar, sizeof(int), n * ARR_SIZE, f);
  fclose(f);
}

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

void Init(int * bigchar)
{
  loadFont(bigchar, 18);
  int status = CheckOutputStream();
  if (!status)
  {
    exit(EXIT_FAILURE);
  }

  InitMem();
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

void printAll()
{
  printMem();
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
}

int main()
{
  int bigchars[18][2];

  Init(*bigchars);
  printBigchars(2, bigchars);

  sc_accumulatorSet(1234);
  sc_icounterSet(2234);

  printAll();

  mt_gotoXY(1, 28);

  return 0;
}
