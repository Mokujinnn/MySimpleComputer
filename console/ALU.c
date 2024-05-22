#include "console.h"
#include "mySimpleComputer.h"

void
ALU_ADD (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  sc_memoryGet (cell, &memory);

  sc_accumulatorSet ((accumulator + memory) & 0x7fff);
}

void
ALU_SUB (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  sc_memoryGet (cell, &memory);

  sc_accumulatorSet ((accumulator + (~memory + 1)) & 0x7fff);
}

void
ALU_DIVIDE (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  sc_memoryGet (cell, &memory);

  if (memory == 0)
    {
      sc_regSet (DIVISION_BY_ZERO, 1);
      sc_regSet (IGNORE_INTERRUPT, 1);
    }

  int accumulator_sign = accumulator >> 14;
  int memory_sign = memory >> 14;
  int value = (accumulator / memory) & 0x3fff;
  if (accumulator_sign ^ memory_sign)
    {
      value = value | 0x4000;
    }

  sc_accumulatorSet (value);
}

void
ALU_MUL (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  sc_memoryGet (cell, &memory);

  int accumulator_sign = accumulator >> 14;
  int memory_sign = memory >> 14;

  // if (accumulator_sign)
  // {
  //     accumulator = ~accumulator + 1;
  // }
  // if (memory_sign)
  // {
  //     memory = ~memory + 1;
  // }

  int value = (memory * accumulator) & 0x3fff;

  if (accumulator_sign ^ memory_sign)
    {
      value = (~value + 1) | 0x4000;
    }

  sc_accumulatorSet (value);
}

void
ALU_NOT (int cell)
{
  int value = 0;
  sc_accumulatorGet (&value);
  sc_memorySet (cell, (~value & 0x7fff));
}

void
ALU_AND (int cell)
{
  int value = 0;
  int mem = 0;
  sc_accumulatorGet (&value);
  sc_memoryGet (cell, &mem);
  sc_accumulatorSet (mem & value);
}

void
ALU (int command, int operand)
{
  switch (command)
    {
    case ADD:
      ALU_ADD (operand);
      break;
    case SUB:
      ALU_SUB (operand);
      break;
    case DIVIDE:
      ALU_DIVIDE (operand);
      break;
    case MUL:
      ALU_MUL (operand);
      break;
    case NOT:
      ALU_NOT (operand);
      break;
    case AND:
      ALU_AND (operand);
      break;
    default:
      break;
    }
}