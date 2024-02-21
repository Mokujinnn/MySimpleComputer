#include <stdio.h>
#include <unistd.h>

#include "mySimpleComputer.h"

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

  snprintf (&str[5], 15, "%.2x%.2x hex: %.4x", command, operand, value);
  write (STDOUT_FILENO, str, 21);
}