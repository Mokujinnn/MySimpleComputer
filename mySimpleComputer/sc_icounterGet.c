#include "sc_variables.h"

int
sc_icounterGet (int *value)
{
  if (!value)
    {
      return -1;
    }

  *value = INST_COUNTER;
  return 0;
}