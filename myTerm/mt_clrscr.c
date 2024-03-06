#include <unistd.h>

int
mt_clrscr ()
{
  write (STDOUT_FILENO, "\E[H\E[2J", 8);
  return 0;
}