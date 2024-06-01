#include "sc_variables.h"

int sc_cacheSet(int, int);
int sc_cacheGet(int, int*);

int
sc_memoryGet (int address, int *value)
{
  if (!(address >= 0 && address < SIZEMEM) || !value)
    {
      return -1;
    }

  if (IGNORE_CACHE)
  {
    *value = MEM[address];
    return 0;
  }
  
  if (sc_cacheGet(address, value))
  {
    sc_cacheSet(address, *value);
    return -2;
  }

  return 0;
}