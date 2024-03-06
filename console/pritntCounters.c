#include <unistd.h>

#include "mySimpleComputer.h"
#include "myTerm.h"

void
printCounters ()
{
  int value = 0;
  char str[10] = "IC: +";

  sc_icounterGet (&value);

  snprintf (&str[5], 5, "%.4x", value);

  mt_gotoXY (63, 5);
  write (STDOUT_FILENO, str, 10);
}