#ifndef SC_VARIABLES_H
#define SC_VARIABLES_H

#include <stdio.h>

enum SIZE
{
	SIZEMEM = 128
};

#ifndef SC_PUBLIC_INTERFACE

extern int MEM[SIZEMEM];
extern int ACC;
extern size_t INST_COUNTER;
extern int REG_FLAG;

#endif // SC_PUBLIC_INTERFACE

// Flag registers

enum FLAGS
{
    OWERFLOW = 0,            //Default state: 0
    DIVISION_BY_ZERO,        //Default state: 0
    OUTMEM,                  //Default state: 0
    WRONG_COMMAND,           //Default state: 0
    IGNORE_INTERRUPT,        //Default state: 1  

    NUMBER_OF_FLAGS
};

#endif // SC_VARIABLES_H