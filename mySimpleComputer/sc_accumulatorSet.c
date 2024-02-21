#include "sc_variables.h"
#include <limits.h>

int
sc_accumulatorSet (int value)
{
  if (value > 0x7fff - 1 || value < -0x7fff)
    {
      return -1;
    }

  ACC = value;
  return 0;
}