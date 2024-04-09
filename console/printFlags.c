#include <unistd.h>

#include "myBigChars.h"
#include "mySimpleComputer.h"
#include "myTerm.h"

void
printFlags ()
{
  char str[10] = "P 0 M E T";

  bc_box (83, 1, 111, 3, ForegroundDefault, BackgroundDefault, "Flags",
          ForegroundDarkRed, BackgroundDefault);
  for (int i = 0, k = 1; i < NUMBER_OF_FLAGS; ++i, k *= 2)
    {
      int value = -1;
      sc_regGet (k, &value);

      if (!value)
        {
          str[2 * i] = '_';
        }
    }

  mt_gotoXY (92, 2);
  write (STDOUT_FILENO, str, 10);
}