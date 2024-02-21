#include "mySimpleComputer.h"
#include <unistd.h>

void
printCounters ()
{
  int value = 0;
  char str[10] = "IC: +";

  sc_icounterGet (&value);

  snprintf (&str[5], 5, "%.4x", value);
  write(STDOUT_FILENO, str, 10);
}