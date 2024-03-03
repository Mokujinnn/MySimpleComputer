#ifndef CONSOLE_H
#define CONSOLE_H

#include "myTerm.h"

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();

#endif // CONSOLE_H