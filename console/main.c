#include <stdio.h>

#include "mySimpleComputer.h"
#include "incl.h"

int main()
{
	sc_regInit();
	sc_accumulatorInit();

	sc_accumulatorSet(1527);

	int value = 0;
	sc_memoryInit();

	sc_commandEncode(1, 15, 1, &value);

	printf("%d\n", value);

	sc_memorySet(0, value);

	// printCell(0);

	// printFlags();

	// printDecodedCommand(127);

	printAccumulator();

	return 0;
}
