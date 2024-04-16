#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myReadKey.h"

void loadFont(int *bigchar, int n)
{
  FILE *f = fopen("font/font.bin", "rb");

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

void Init(int *bigchar)
{
  loadFont(bigchar, 18);
  int status = CheckOutputStream();
  if (!status)
  {
    exit(EXIT_FAILURE);
  }

  InitMem();
}

void printMem(int addresOfCurrentCell)
{
  for (int i = 0; i < SIZEMEM; ++i)
  {
    printCell(i, ForegroundDefault, BackgroundDefault);
  }
  printCell(addresOfCurrentCell, ForegroundBlack, BackgroundLightGray);
}

void printAllBoxes()
{
  bc_box(1, 1, 61, 15, ForegroundDefault, BackgroundDefault, " Оперативная память ",
         ForegroundDarkRed, ForegroundDefault);
  bc_box(1, 16, 61, 18, ForegroundDefault, BackgroundDefault,
         " Редактируемая ячейка (декодированно) ", ForegroundDarkRed,
         BackgroundDefault);
  bc_box(62, 1, 87, 3, ForegroundDefault, BackgroundDefault, " Аккумулятор ",
         ForegroundDarkRed, BackgroundDefault);
  bc_box(62, 4, 87, 6, ForegroundDefault, BackgroundDefault,
         " Счётчик инструкций ", ForegroundDarkRed, BackgroundDefault);
  bc_box(88, 4, 111, 6, ForegroundDefault, BackgroundDefault, " Команда ",
         ForegroundDarkRed, BackgroundDefault);
  bc_box(88, 1, 111, 3, ForegroundDefault, BackgroundDefault, " Флаги ",
         ForegroundDarkRed, BackgroundDefault);
  bc_box(62, 7, 111, 18, ForegroundDefault, BackgroundDefault,
         " Редактируемая ечейка (увеличено) ", ForegroundDarkRed,
         ForegroundDefault);
  bc_box(63, 19, 73, 25, ForegroundDefault, BackgroundDefault, " IN--OUT ",
         ForegroundDarkRed, BackgroundLightGray);
  bc_box(1, 19, 62, 25, ForegroundDefault, BackgroundDefault, " Кеш Память ",
         ForegroundDarkRed, BackgroundDefault);
  bc_box(74, 19, 111, 25, ForegroundDefault, BackgroundDefault, " Клавиатура ",
         ForegroundDarkRed, BackgroundDefault);
}

void UpdateAll(int bigchars[][ARR_SIZE], int addresOfCurrentCell)
{
  printMem(addresOfCurrentCell);
  printFlags();
  printDecodedCommand(addresOfCurrentCell);
  printAccumulator();
  printCounters();
  printCommand();
  printBigCell(addresOfCurrentCell, bigchars);

  // for (int i = 0; i < 7; i++)
  // {
  printTerm(0, 0);
  //   getchar();
  // }
}

int main()
{
  int bigchars[18][2];
  int currentCell = 0;
  int escIsNotPresed = 1;
  Init(*bigchars);

  mt_setcursorvisible(0);

  printAllBoxes();

  rk_mytermregime(0, 1, 1, 0, 0);
  UpdateAll(bigchars, currentCell);

  while (escIsNotPresed)
  {
    enum keys key = -1;
    rk_readkey(&key);

    switch (key)
    {
    case ESC:
      escIsNotPresed = 0;
      break;
    case LEFT:
      if (currentCell == 120)
      {
        currentCell += 7;
      }
      else if (currentCell % 10 == 0)
        currentCell += 9;
      else
        currentCell -= 1;
      break;
    case RIGHT:
      if (currentCell == 127)
      {
        currentCell -= 7;
      }
      else if (currentCell % 10 == 9)
        currentCell -= 9;
      else
        currentCell += 1;
      break;
    case UP:
      if (currentCell == 8 || currentCell == 9)
      {
        currentCell += 110;
      }
      else if (currentCell < 10)
        currentCell += 120;
      else
        currentCell -= 10;
      break;
    case DOWN:
      if (currentCell == 118 || currentCell == 119)
      {
        currentCell -= 110;
      }
      else if (currentCell > 119)
        currentCell -= 120;
      else
        currentCell += 10;
      break;
    default:
      break;
    }

    UpdateAll(bigchars, currentCell);
  }

  mt_setcursorvisible(1);

  return 0;
}
