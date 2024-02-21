#include <stdio.h>
#include "sc_variables.h"

int sc_memorySave(char *filename)
{
	FILE *fp = fopen(filename, "wb");
	if (!fp)
	{
		return -1;
	}

	fwrite(MEM, sizeof(int), SIZEMEM, fp);

	fclose(fp);

	return 0;
}