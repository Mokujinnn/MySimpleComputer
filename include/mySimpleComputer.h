#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#define SC_PUBLIC_INTERFACE
#include "../mySimpleComputer/sc_variables.h"


void sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int *value);
int sc_memorySave(char *filename);
int sc_memoryLoad(char *filename);
void sc_regInit();
int sc_regSet(int reg, int value);
int sc_regGet(int reg, int *value);
void sc_accumulatorInit();
int sc_accumulatorSet(int value);
int sc_accumulatorGet(int * value);
void sc_icounterInit();
int sc_icounterSet (int value);
int sc_icounterGet (int * value);
int sc_commandEncode(int sign, int command, int operand, int * value);
int sc_commandDecode(int value, int * sign, int * command, int * operand);
int sc_commandValidate(int command);

#endif // MY_SIMPLE_COMPUTER_H