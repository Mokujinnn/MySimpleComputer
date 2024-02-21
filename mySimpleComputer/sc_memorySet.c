#include "sc_variables.h"

int sc_memorySet(int address, int value)
{
	if (!(address >= 0 && address < SIZEMEM) && !value)
	{
		return -1;
	}

	MEM[address] = value;
	return 0;
}