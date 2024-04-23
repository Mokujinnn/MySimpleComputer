#include <string.h>
#include <unistd.h>

#include "myReadKey.h"

#include <stdio.h>

int
rk_readkey (enum keys *key)
{
  char buf[7] = { 0 };
  int len = 0;
  int r = read (STDIN_FILENO, buf, 6);
  if (r == -1)
    {
      return -1;
    }

  len = strlen (buf);

  if (len == 1)
    {
      if (strncmp (buf, "a", 1) == 0)
        *key = A;
      else if (strncmp (buf, "b", 1) == 0)
        *key = B;
      else if (strncmp (buf, "c", 1) == 0)
        *key = C;
      else if (strncmp (buf, "d", 1) == 0)
        *key = D;
      else if (strncmp (buf, "e", 1) == 0)
        *key = E;
      else if (strncmp (buf, "f", 1) == 0)
        *key = F;
      else if (strncmp (buf, "l", 1) == 0)
        *key = L;
      else if (strncmp (buf, "s", 1) == 0)
        *key = S;
      else if (strncmp (buf, "r", 1) == 0)
        *key = R;
      else if (strncmp (buf, "t", 1) == 0)
        *key = T;
      else if (strncmp (buf, "i", 1) == 0)
        *key = I;
      else if (strncmp (buf, "v", 1) == 0)
        *key = V;
      else if (strncmp (buf, "p", 1) == 0)
        *key = P;
      else if (strncmp (buf, "q", 1) == 0)
        *key = Q;
      else if (strncmp (buf, "0", 1) == 0)
        *key = NUM0;
      else if (strncmp (buf, "1", 1) == 0)
        *key = NUM1;
      else if (strncmp (buf, "2", 1) == 0)
        *key = NUM2;
      else if (strncmp (buf, "3", 1) == 0)
        *key = NUM3;
      else if (strncmp (buf, "4", 1) == 0)
        *key = NUM4;
      else if (strncmp (buf, "5", 1) == 0)
        *key = NUM5;
      else if (strncmp (buf, "6", 1) == 0)
        *key = NUM6;
      else if (strncmp (buf, "7", 1) == 0)
        *key = NUM7;
      else if (strncmp (buf, "8", 1) == 0)
        *key = NUM8;
      else if (strncmp (buf, "9", 1) == 0)
        *key = NUM9;
      else if (strncmp (buf, "-", 1) == 0)
        *key = MINUS;
      else if (strncmp (buf, "+", 1) == 0)
        *key = PLUS;
      else if (strncmp (buf, "\E", 1) == 0)
        *key = ESC;
      else if (strncmp (buf, "\n", 1) == 0)
        *key = ENTER;
      else
        *key = UNKNOWN;
    }
  else if (len == 3)
    {
      if (strncmp (buf, "\E[A", 3) == 0)
        *key = UP;
      else if (strncmp (buf, "\E[B", 3) == 0)
        *key = DOWN;
      else if (strncmp (buf, "\E[C", 3) == 0)
        *key = RIGHT;
      else if (strncmp (buf, "\E[D", 3) == 0)
        *key = LEFT;
      else
        *key = UNKNOWN;
    }
  else if (len == 5)
    {
      if (strncmp (buf, "\E[15~", 5) == 0)
        *key = F5;
      else if (strncmp (buf, "\E[17~", 5) == 0)
        *key = F6;
      else
        *key = UNKNOWN;
    }
  else
    *key = UNKNOWN;

  return 0;
}