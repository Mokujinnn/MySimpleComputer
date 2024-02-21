#include <stdio.h>

#include "sc_variables.h"

void sc_memoryInit()
{
	for (int i = 0; i < SIZEMEM; ++i)
	{
		MEM[i] = 0;
	}
}

int sc_memorySet(int address, int value)
{
	if (!(address >= 0 && address < SIZEMEM) && !value)
	{
		return -1;
	}

	MEM[address] = value;
	return 0;
}

int sc_memoryGet(int address, int *value)
{
	if (!(address >= 0 && address < SIZEMEM) && !value)
	{
		return -1;
	}

	*value = MEM[address];
	return 0;
}

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

int sc_memoryLoad(char *filename)
{
	FILE *fp = fopen(filename, "rb");
	if (!fp)
	{
		return -1;
	}

	fread(MEM, sizeof(int), SIZEMEM, fp);

	fclose(fp);

	return 0;
}