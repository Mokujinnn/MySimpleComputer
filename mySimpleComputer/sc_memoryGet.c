#include "sc_variables.h"

int sc_memoryGet(int address, int *value)
{
	if (!(address >= 0 && address < SIZEMEM) && !value)
	{
		return -1;
	}

	*value = MEM[address];
	return 0;
}