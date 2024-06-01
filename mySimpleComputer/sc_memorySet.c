#include "sc_variables.h"

int sc_cacheSet (int, int);

int
sc_memorySet (int address, int value)
{
  if (!(address >= 0 && address < SIZEMEM) || value < -0x7fff
      || value > 0x7fff - 1)
    {
      return -1;
    }

  if (IGNORE_CACHE)
    {
      MEM[address] = value;
      return 0;
    }

  if (sc_cacheSet (address, value))
    {
      return -2;
    }

  return 0;
}