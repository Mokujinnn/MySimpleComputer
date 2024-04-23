#include <stdio.h>
#include <termios.h>
#include <unistd.h>

int
rk_mytermsave ()
{
  struct termios term;
  FILE *file = fopen ("terminalsettings.bin", "wb");

  if (tcgetattr (STDIN_FILENO, &term) != 0 || file == NULL)
    {
      return -1;
    }

  fwrite (&term, sizeof (term), 1, file);
  fclose (file);

  return 0;
}