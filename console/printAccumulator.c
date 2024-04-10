#include <stdio.h>
#include <unistd.h>

#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

void
printAccumulator ()
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[21] = "sc: ";

  bc_box (62, 1, 82, 3, ForegroundDefault, BackgroundDefault, "Аккумулятор",
          ForegroundDarkRed, BackgroundDefault);

  sc_accumulatorGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[4] = sign == 0 ? '+' : '-';

  snprintf (&str[5], 15, "%.2x%.2x hex: %.4x", command, operand, value);

  mt_gotoXY (63, 2);
  write (STDOUT_FILENO, str, 21);
}