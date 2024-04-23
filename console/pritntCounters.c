#include <unistd.h>

#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

void
printCounters ()
{
  int value = 0;
  int sign = 0;
  int command = 0;
  int operand = 0;
  char str[10] = "IC: ";

  sc_icounterGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  str[4] = sign == 0 ? '+' : '-';

  snprintf (&str[5], 5, "%.2x%.2x", command, operand);

  mt_gotoXY (65, 5);
  write (STDOUT_FILENO, str, 10);
}