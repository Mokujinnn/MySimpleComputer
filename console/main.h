#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "console.h"
#include "myBigChars.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"

#define INPUTCELL 0
#define INPUTACCUM 1
#define INPUTICOUNTER 2

void
loadFont (int *bigchar, int n)
{
  FILE *f = fopen ("font/font.bin", "rb");

  if (f == NULL)
    {
      printf ("Cant open file with font\n");
      exit (EXIT_FAILURE);
    }

  fread (bigchar, sizeof (int), n * ARR_SIZE, f);
  fclose (f);
}

void
InitMem ()
{
  sc_memoryInit ();
  for (int i = 0; i < rand () % SIZEMEM; ++i)
    {
      sc_memorySet (i, rand () % 0x7fff);
    }

  sc_regInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
}

int
CheckOutputStream ()
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
  return 1;
}

void
Init (int *bigchar)
{
  loadFont (bigchar, 18);
  int status = CheckOutputStream ();
  if (!status)
    {
      exit (EXIT_FAILURE);
    }

  InitMem ();
}

void
printMem (int addresOfCurrentCell)
{
  for (int i = 0; i < SIZEMEM; ++i)
    {
      printCell (i, ForegroundDefault, BackgroundDefault);
    }
  printCell (addresOfCurrentCell, ForegroundBlack, BackgroundLightGray);
}

void
printKeybord ()
{
  mt_gotoXY (75, 20);
  write (STDOUT_FILENO, "l - load  s - save i - reset", 29);
  mt_gotoXY (75, 21);
  write (STDOUT_FILENO, "r - run  t - step", 18);
  mt_gotoXY (75, 22);
  write (STDOUT_FILENO, "ESC - выход", 17);
  mt_gotoXY (75, 23);
  write (STDOUT_FILENO, "F5 - accumulator", 17);
  mt_gotoXY (75, 24);
  write (STDOUT_FILENO, "F6 - instruction counter", 25);
}

void
printAllBoxes ()
{
  bc_box (1, 1, 61, 15, ForegroundDefault, BackgroundDefault,
          " Оперативная память ", ForegroundDarkRed, ForegroundDefault);
  bc_box (1, 16, 61, 18, ForegroundDefault, BackgroundDefault,
          " Редактируемая ячейка (декодированно) ", ForegroundDarkRed,
          BackgroundDefault);
  bc_box (62, 1, 87, 3, ForegroundDefault, BackgroundDefault, " Аккумулятор ",
          ForegroundDarkRed, BackgroundDefault);
  bc_box (62, 4, 87, 6, ForegroundDefault, BackgroundDefault,
          " Счётчик инструкций ", ForegroundDarkRed, BackgroundDefault);
  bc_box (88, 4, 111, 6, ForegroundDefault, BackgroundDefault, " Команда ",
          ForegroundDarkRed, BackgroundDefault);
  bc_box (88, 1, 111, 3, ForegroundDefault, BackgroundDefault, " Флаги ",
          ForegroundDarkRed, BackgroundDefault);
  bc_box (62, 7, 111, 18, ForegroundDefault, BackgroundDefault,
          " Редактируемая ечейка (увеличено) ", ForegroundDarkRed,
          ForegroundDefault);
  bc_box (63, 19, 73, 25, ForegroundDefault, BackgroundDefault, " IN--OUT ",
          ForegroundDarkRed, BackgroundLightGray);
  bc_box (1, 19, 62, 25, ForegroundDefault, BackgroundDefault, " Кеш Память ",
          ForegroundDarkRed, BackgroundDefault);
  bc_box (74, 19, 111, 25, ForegroundDefault, BackgroundDefault,
          " Клавиатура ", ForegroundDarkRed, BackgroundDefault);
}

void
UpdateAll (int bigchars[][ARR_SIZE], int addresOfCurrentCell)
{
  printMem (addresOfCurrentCell);
  printFlags ();
  printDecodedCommand (addresOfCurrentCell);
  printAccumulator ();
  printCounters ();
  printCommand ();
  printBigCell (addresOfCurrentCell, bigchars);
  printTerm (0, 0);
}

void
InPlaceInput (int line, int colmn, int type)
{
  int value = -1;

  mt_setcursorvisible (1);

  mt_gotoXY (colmn, line);
  write (STDOUT_FILENO, "     ", 5);
  mt_gotoXY (colmn, line);

  rk_readvalue (&value, 10);

  if (value == -1)
    {
      return;
    }

  if (type == INPUTCELL)
    {
      sc_memorySet (((line - 2) * 10 + (colmn - 2) / 6), value);
    }
  else if (type == INPUTACCUM)
    {
      sc_accumulatorSet (value);
    }
  else if (type == INPUTICOUNTER)
    {
      sc_icounterSet (value);
    }

  rk_mytermrestore ();
  mt_setcursorvisible (0);
}

void
MemorySave ()
{
  char buf[128] = { 0 };

  mt_gotoXY (1, 26);
  write (STDOUT_FILENO, "Введите имя файла для сохранения: ", 63);

  mt_setcursorvisible (1);
  rk_mytermsave ();

  rk_mytermregime (1, 1, 1, 1, 0);

  read (STDIN_FILENO, buf, 127);
  buf[bc_strlen (buf) - 1] = '\0';

  sc_memorySave (buf);

  rk_mytermrestore ();
  mt_setcursorvisible (0);

  mt_gotoXY (1, 26);
  mt_delline ();
}

void
MemoryLoad ()
{
  char buf[128] = { 0 };

  mt_gotoXY (1, 26);
  write (STDOUT_FILENO, "Введите имя файла для загрузки: ", 59);

  mt_setcursorvisible (1);
  rk_mytermsave ();

  rk_mytermregime (1, 1, 1, 1, 0);

  read (STDIN_FILENO, buf, 127);
  buf[bc_strlen (buf) - 1] = '\0';

  sc_memoryLoad (buf);

  rk_mytermrestore ();
  mt_setcursorvisible (0);

  mt_gotoXY (1, 26);
  mt_delline ();
}

void
MemoryReset ()
{
  sc_memoryInit ();
}

void
Control (enum keys key, int *currentCell, int *escIsNotPressed)
{
  switch (key)
    {
    case ESC:
      *escIsNotPressed = 0;
      break;
    case LEFT:
      if (*currentCell == 120)
        {
          *currentCell += 7;
        }
      else if (*currentCell % 10 == 0)
        *currentCell += 9;
      else
        *currentCell -= 1;
      break;
    case RIGHT:
      if (*currentCell == 127)
        {
          *currentCell -= 7;
        }
      else if (*currentCell % 10 == 9)
        *currentCell -= 9;
      else
        *currentCell += 1;
      break;
    case UP:
      if (*currentCell == 8 || *currentCell == 9)
        {
          *currentCell += 110;
        }
      else if (*currentCell < 10)
        *currentCell += 120;
      else
        *currentCell -= 10;
      break;
    case DOWN:
      if (*currentCell == 118 || *currentCell == 119)
        {
          *currentCell -= 110;
        }
      else if (*currentCell > 119)
        *currentCell -= 120;
      else
        *currentCell += 10;
      break;
    case ENTER:
      InPlaceInput (*currentCell / 10 + 2, (*currentCell % 10) * 6 + 2,
                    INPUTCELL);
      break;
    case F5:
      InPlaceInput (2, 69, INPUTACCUM);
      break;
    case F6:
      InPlaceInput (5, 69, INPUTICOUNTER);
      break;
    case L:
      MemoryLoad ();
      break;
    case S:
      MemorySave ();
      break;
    case I:
      MemoryReset ();
      break;
    default:
      break;
    }
}

#undef INPUTCELL
#undef INPUTACCUM
#undef INPUTICOUNTER