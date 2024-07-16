#include "console.h"
#include "mySimpleComputer.h"

int
ALU_ADD (int cell)
{
  int accumulator_value, memory_value;
  sc_accumulatorGet (&accumulator_value);
  if (sc_memoryGet (cell, &memory_value) == -2)
    return -3;
  return (((accumulator_value << 17) + (memory_value << 17)) >> 17) & 0x7FFF;
}

int
ALU_SUB (int cell)
{
  int accumulator_value, memory_value;
  sc_accumulatorGet (&accumulator_value);
  if (sc_memoryGet (cell, &memory_value) == -2)
    return -3;
  return (((accumulator_value << 17) + ((~memory_value + 1) << 17)) >> 17)
         & 0x7FFF;
}

int
ALU_DIVIDE (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  if (sc_memoryGet (cell, &memory) == -2)
    return -3;

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

  return (value);
}

int
ALU_MUL (int cell)
{
  int accumulator = 0;
  int memory = 0;

  sc_accumulatorGet (&accumulator);
  if (sc_memoryGet (cell, &memory) == -2)
    return -3;

  int accumulator_sign = accumulator >> 14;
  int memory_sign = memory >> 14;

  int value = (memory * accumulator) & 0x3fff;

  if (accumulator_sign ^ memory_sign)
    {
      value = ((~value & 0x3FFF) + 1) | 0x4000;
    }

  return (value);
}

int
ALU_NOT (int cell)
{
  int value = 0;
  sc_accumulatorGet (&value);
  if (sc_memorySet (cell, (~value & 0x7fff)) == -2)
    return -3;

  return 0;
}

int
ALU_AND (int cell)
{
  int value = 0;
  int mem = 0;
  if (sc_accumulatorGet (&value) == -2)
    return -3;
  if (sc_memoryGet (cell, &mem) == -2)
    return -3;
  sc_accumulatorSet (mem & value);

  return 0;
}

int
ALU (int command, int operand)
{
  switch (command)
    {
    case ADD:
      return ALU_ADD (operand);
      break;
    case SUB:
      return ALU_SUB (operand);
      break;
    case DIVIDE:
      return ALU_DIVIDE (operand);
      break;
    case MUL:
      return ALU_MUL (operand);
      break;
    case NOT:
      return ALU_NOT (operand);
      break;
    case AND:
      return ALU_AND (operand);
      break;
    default:
      break;
    }
  return 0;
}