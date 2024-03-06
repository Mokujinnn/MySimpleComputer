#include <unistd.h>

int
mt_setdefaultcolor ()
{
  write (STDOUT_FILENO, "\E[39;49m", 9);
  return 0;
}