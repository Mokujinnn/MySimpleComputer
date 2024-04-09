#include "myBigChars.h"

int
bc_getbigcharpos (int big[ARR_SIZE], int x, int y, int *value)
{
  if (value == NULL || big == NULL)
    {
      return -1;
    }

  *value = (big[y / sizeof (int)] >> (x + ((y % 4) * BITS_IN_BYTE))) & 1;
  return 0;
}