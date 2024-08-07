#include "sc_variables.h"
#include <stdio.h>

int
sc_memoryLoad (char *filename)
{
  FILE *fp = fopen (filename, "rb");
  if (!fp)
    {
      return -1;
    }

  fread (MEM, sizeof (int), SIZEMEM, fp);

  fclose (fp);

  return 0;
}