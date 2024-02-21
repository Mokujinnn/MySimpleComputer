#include <stdio.h>

#include "mySimpleComputer.h"

void
printCell (int address)
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[6];

  sc_memoryGet (address, &value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[0] = sign == 0 ? '+' : '-';

  snprintf (&str[1], 5, "%.2x%.2x", command, operand);
  fwrite (str, 1, 6, stdout);
}