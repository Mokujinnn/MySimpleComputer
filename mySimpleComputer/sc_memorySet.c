#include "sc_variables.h"

int sc_memorySet(int address, int value)
{
	if (!(address >= 0 && address < SIZEMEM) || value < -0x7fff || value > 0x7fff - 1)
	{
		return -1;
	}

	MEM[address] = value;
	return 0;
}