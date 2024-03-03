#include <stdio.h>
#include <unistd.h>

#include "mySimpleComputer.h"
#include "myTerm.h"

void printCell (int address, enum colors fg, enum colors bg)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[6] = { 0 };
  int line = address / 10;
  int colmn = (address % 10) * 6;

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[0] = sign == 0 ? '+' : '-';

  snprintf (&str[1], 5, "%.2x%.2x", command, operand);

  mt_setbgcolor(bg);
  mt_setfgcolor(fg);
  mt_gotoXY(2 + colmn, 2 + line);

  write (STDOUT_FILENO, str, 6);
  mt_setdefaultcolor();
}