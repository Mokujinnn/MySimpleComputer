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

  sc_accumulatorGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[4] = sign == 0 ? '+' : '-';

  if (sign)
    {
      value = (~value & 0x3FFF) + 1;
      sc_commandDecode (value, &sign, &command, &operand);
    }

  snprintf (&str[5], 15, "%.2x%.2x hex: %.4x", command, operand, value);

  mt_gotoXY (65, 2);
  write (STDOUT_FILENO, str, 21);
}