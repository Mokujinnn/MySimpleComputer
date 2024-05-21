#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "myReadKey.h"
#include "mySimpleComputer.h"

int
rk_readvalue (int *value, int timeout)
{
  int buf[5] = { 0 };
  enum keys key[5] = { 0 };
  int flag = 1;

  rk_mytermsave ();
  rk_mytermregime (0, timeout, 1, 1, 0);

  for (int i = 0; i < 5; i++)
    {
      rk_readkey (key + i);
      enum keys k = key[i];
      if (i == 0)
        {
          flag = (k == PLUS || k == MINUS);
        }
      else if (i == 1)
        {
          flag = (k >= NUM0 && k <= NUM5);
        }
      else if (i == 2 || i == 4)
        {
          flag = (k >= NUM0 && k <= F);
        }
      else if (i == 3)
        {
          flag = (k >= NUM0 && k <= NUM7);
        }

      if (!flag)
        {
          rk_mytermrestore ();
          return -1;
        }

      if (k == PLUS || k == MINUS)
        {
          buf[i] = k - PLUS;
        }
      else
        {
          buf[i] = k - NUM0;
        }
    }

  sc_commandEncode (buf[0], buf[1] * 16 + buf[2], buf[3] * 16 + buf[4], value);

  rk_mytermrestore ();

  return 0;
}