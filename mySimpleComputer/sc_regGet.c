#include "sc_variables.h"

int
sc_regGet (int reg, int *value)
{
  if (!(reg == OWERFLOW || reg == DIVISION_BY_ZERO || reg == OUTMEM
        || reg == WRONG_COMMAND || reg == IGNORE_INTERRUPT)
      || !value)
    {
      return -1;
    }

  *value = REG_FLAG & reg ? 1 : 0;

  return 0;
}