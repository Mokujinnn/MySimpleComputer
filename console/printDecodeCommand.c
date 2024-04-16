#include <stdio.h>
#include <unistd.h>

#include "myBigChars.h"
#include "myTerm.h"

void
printDecodedCommand (int value)
{
  char bin[16] = { 0 };
  char str[60] = { 0 };
  int tmp = value;

  for (int i = 0; i < 15; ++i)
    {
      bin[15 - i - 1] = ((tmp >> i) & 1) + '0';
    }

  snprintf (str, 60, "dec: %.5d | oct: %.6o | hex: %.4x | bin: %s", value,
            value, value, bin);

  mt_gotoXY (2, 17);
  write (STDOUT_FILENO, str, 60);
}