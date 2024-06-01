#ifndef SC_VARIABLES_H
#define SC_VARIABLES_H

#include <stdio.h>

enum SIZE
{
  SIZEMEM = 128,
  CACHESIZE = 5
};

#ifndef SC_PUBLIC_INTERFACE

extern int MEM[SIZEMEM];
extern int ACC;
extern int TCOUNTER;
extern int INST_COUNTER;
extern int REG_FLAG;

typedef struct
{
  int downtime;
  int address;
  int line[10];
} Cacheline;

extern Cacheline CACHE[CACHESIZE];
extern int IGNORE_CACHE;

#endif // SC_PUBLIC_INTERFACE

// Flag registers

enum FLAGS
{
  OWERFLOW = 0x01,         // Default state: 0
  DIVISION_BY_ZERO = 0x02, // Default state: 0
  OUTMEM = 0x04,           // Default state: 0
  WRONG_COMMAND = 0x08,    // Default state: 0
  IGNORE_INTERRUPT = 0x10, // Default state: 1

  NUMBER_OF_FLAGS = 5
};

#endif // SC_VARIABLES_H