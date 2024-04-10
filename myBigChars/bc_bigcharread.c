#include <unistd.h>

#include "myBigChars.h"

int
bc_bigcharread (int fd, int *big, int need_count, int *count)
{
  if (big == NULL || count == NULL)
    {
      return -1;
    }

  *count = read (fd, big, need_count * sizeof (int) * ARR_SIZE)
           / (sizeof (int) * ARR_SIZE);
  return 0;
}