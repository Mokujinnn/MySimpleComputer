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
  char str1[10] = "IC: ";
  char str2[7] = "T: ";

  sc_icounterGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  str1[4] = sign == 0 ? '+' : '-';

  snprintf (&str1[5], 5, "%.2x%.2x", command, operand);

  sc_tcounterGet (&value);
  sc_commandDecode (value, &sign, &command, &operand);

  snprintf (&str2[4], 3, "%.2x", operand);

  mt_gotoXY (65, 5);
  write (STDOUT_FILENO, str1, 10);

  mt_gotoXY (75, 5);
  write (STDOUT_FILENO, str2, 7);
}