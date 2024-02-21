#include <stdio.h>

#include "mySimpleComputer.h"
#include "incl.h"

int main()
{
	sc_regInit();
	sc_accumulatorInit();
	sc_icounterInit();

	sc_accumulatorSet(1527);

	int value = 0;
	sc_memoryInit();

	sc_commandEncode(1, 15, 1, &value);

	printf("%d\n", value);

	sc_memorySet(0, value);

	// printCell(0);

	// printFlags();

	// printDecodedCommand(127);

	// printAccumulator();

	sc_icounterSet(1000);

	printCounters();

	return 0;
}
