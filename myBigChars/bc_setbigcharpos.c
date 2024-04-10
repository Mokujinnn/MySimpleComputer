#include "myBigChars.h"

int
bc_setbigcharpos (int big[ARR_SIZE], int x, int y, int value)
{
  if (big == NULL)
    {
      return -1;
    }

  if (value == 0)
    {
      big[y / sizeof (int)]
          = big[y / sizeof (int)] & ~(1 << (x + ((y % 4) * BITS_IN_BYTE)));
    }
  else
    {
      big[y / sizeof (int)]
          = big[y / sizeof (int)] | (1 << (x + ((y % 4) * BITS_IN_BYTE)));
    }
  return 0;
}