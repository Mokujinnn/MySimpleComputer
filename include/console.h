#ifndef CONSOLE_H
#define CONSOLE_H

#include "myBigChars.h"
#include "myTerm.h"
#include <inttypes.h>

enum commands
{
  NOP = 0x00,
  CPUINFO = 0x01,
  READ = 0x0A,
  WRITE = 0x0B,
  LOAD = 0x14,
  STORE = 0x15,
  ADD = 0x1E,
  SUB = 0x1F,
  DIVIDE = 0x20,
  MUL = 0x21,
  JUMP = 0x28,
  JNEG = 0x29,
  JZ = 0x2A,
  HALT = 0x2B,
  NOT = 0x33,
  AND = 0x34,
  OR = 0x35,
  XOR = 0x36,
  JNS = 0x37,
  JC = 0x38,
  JNC = 0x39,
  JP = 0x3A,
  JNP = 0x3B,
  CHL = 0x3C,
  SHR = 0x3D,
  RCL = 0x3E,
  RCR = 0x3F,
  NEG = 0x40,
  ADDC = 0x41,
  SUBC = 0x42,
  LOGLC = 0x43,
  LOGRC = 0x44,
  RCCL = 0x45,
  RCCR = 0x46,
  MOVA = 0x47,
  MOVR = 0x48,
  MOVCA = 0x49,
  MOVCR = 0x4A,
  ADDC2 = 0x4B,
  SUBC2 = 0x4C
};

void printCell (int address, enum colors fg, enum colors bg);
void printFlags ();
void printDecodedCommand (int value);
void printAccumulator ();
void printCounters ();
void printTerm (int address, int input);
void printCommand ();
void printBigCell (int address, int bigchars[][ARR_SIZE]);
void printCache ();
int ALU (int command, int operand);
void CU ();
void IRC (int signum);

#endif // CONSOLE_H