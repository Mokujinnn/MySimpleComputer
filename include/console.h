#ifndef CONSOLE_H
#define CONSOLE_H

#include "myBigChars.h"
#include "myTerm.h"

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printTerm (int address, int input);
void printCommand ();
void printBigCell (int address, int bigchars[][ARR_SIZE]);

#endif // CONSOLE_H