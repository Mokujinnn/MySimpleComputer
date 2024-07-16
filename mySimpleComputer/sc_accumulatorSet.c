#include "sc_variables.h"
#include <limits.h>

int
sc_accumulatorSet (int value)
{
  if (value < 0 || value > 32767)
    {
      return -1;
    }

  ACC = value;
  return 0;
}