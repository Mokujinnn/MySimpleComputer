#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "myReadKey.h"

int
rk_readvalue (int *value, int timeout)
{
  char buf[10] = { 0 };

  rk_mytermsave ();
  rk_mytermregime (0, timeout, 5, 0, 0);

  read (STDIN_FILENO, buf, 9);

  *value = atoi (buf);

  rk_mytermrestore ();

  return 0;
}