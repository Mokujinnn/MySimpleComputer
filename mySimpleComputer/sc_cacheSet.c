#include "sc_variables.h"
#include <stdbool.h>

int
sc_cacheSet (int address, int value)
{
  if (address < 0 || address >= SIZEMEM)
    {
      return -1;
    }

  int i;
  int max_downtime = 0;
  int displacement = 0;
  int line_size = 10;
  int hit = 0;

  for (i = 0; i < CACHESIZE; i++)
    {
      if (CACHE[i].address == -1)
        {
          break;
        }
      if (CACHE[i].downtime > max_downtime)
        {
          max_downtime = CACHE[i].downtime;
        }
      if (CACHE[i].address == (address - (address % 10)))
        {
          hit = 1;
          break;
        }
    }
  if (hit)
    {
      CACHE[i].line[address % 10] = value;
      return 0;
    }
  else
    TCOUNTER = 10;
  if (i == CACHESIZE)
    {
      displacement = 1;
      for (i = 0; i < CACHESIZE; i++)
        if (CACHE[i].downtime == max_downtime)
          break;
    }

  line_size = CACHE[i].address == 120 ? 8 : 10;
  if (displacement)
    for (int j = 0; j < line_size; j++)
      {
        MEM[CACHE[i].address + j] = CACHE[i].line[j];
      }

  CACHE[i].address = address - (address % 10);
  line_size = CACHE[i].address == 120 ? 8 : 10;
  for (int j = 0; j < line_size; j++)
    {
      CACHE[i].line[j] = MEM[CACHE[i].address + j];
    }
  return -2;
}