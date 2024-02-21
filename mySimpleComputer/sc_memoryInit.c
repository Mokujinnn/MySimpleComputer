#include "sc_variables.h"

void sc_memoryInit()
{
	for (int i = 0; i < SIZEMEM; ++i)
	{
		MEM[i] = 0;
	}
}