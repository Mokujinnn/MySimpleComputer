#include <unistd.h>

#include "myBigChars.h"

int
bc_bigcharwrite (int fd, int *big, int count)
{
  if (big == NULL)
    {
      return -1;
    }

  ssize_t n = write (fd, big, count * sizeof (int) * ARR_SIZE);
  return n == -1 ? -1 : 0;
}