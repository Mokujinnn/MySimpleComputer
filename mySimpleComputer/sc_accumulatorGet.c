#include "sc_variables.h"

int
sc_accumulatorGet (int *value)
{
  if (!value)
    {
      return -1;
    }

  *value = ACC;
  return 0;
}