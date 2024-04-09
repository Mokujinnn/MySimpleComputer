#include <stdio.h>
#include <unistd.h>

int
bc_printA (char *str)
{
  char tmp[128] = { 0 };
  snprintf (tmp, 128, "\E(0%s\E(B", str);
  write (STDOUT_FILENO, tmp, 128);
  return 0;
}