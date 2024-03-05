#include <unistd.h>

int
mt_setcursorvisible (int value)
{
  if (value == 0)
    {
      write (STDOUT_FILENO, "\E[?25l", 7);
      return 0;
    }

  write (STDOUT_FILENO, "\E[?12;25h", 10);
  return 0;
}