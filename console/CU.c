#include "console.h"
#include "myReadKey.h"
#include "mySimpleComputer.h"
#include <unistd.h>

void printKeybord ();

void
CU_CPUINFO ()
{
  mt_gotoXY (79, 20);
  write (STDOUT_FILENO, "Любицкий Максим Егорович, ИС-242",
         sizeof ("Любицкий Максим Егорович, ИС-242"));
  for (int i = 0; i < 4; i++)
    {
      mt_gotoXY (79, 21 + i);
      write (STDOUT_FILENO, "                            ",
             sizeof ("                            "));
    }
  sleep (2);
  mt_gotoXY (79, 20);
  write (STDOUT_FILENO, "                                ",
         sizeof ("                                "));
  printKeybord ();
}

void
CU_READ (int cell)
{
  sc_regSet (IGNORE_INTERRUPT, 1);
  sc_setIgnoreCache (1);
  printTerm (cell, 1);
  sc_setIgnoreCache (0);
  rk_mytermregime (0, 1, 0, 0, 0);
  sc_regSet (IGNORE_INTERRUPT, 0);
}

void
CU_WRITE (int cell)
{
  printTerm (cell, 0);
}

int
CU_LOAD (int cell)
{
  int value = 0;
  if (sc_memoryGet (cell, &value) == -2)
    return -2;
  sc_accumulatorSet (value);
  return 0;
}

int
CU_STORE (int cell)
{
  int value = 0;
  sc_accumulatorGet (&value);
  if (sc_memorySet (cell, value) == -2)
    return -2;
  return 0;
}

void
CU_JUMP (int cell)
{
  sc_icounterSet (cell);
}

void
CU_JNEG (int cell)
{
  int value = 0;
  sc_accumulatorGet (&value);
  if ((value >> 14) > 0)
    {
      sc_icounterSet (cell);
    }
}

void
CU_JZ (int cell)
{
  int value = 0;
  sc_accumulatorGet (&value);
  if ((value & 0x3fff) == 0)
    {
      sc_icounterSet (cell);
    }
}

void
CU_HALT (int cell)
{
  sc_regSet (IGNORE_INTERRUPT, 1);
}

void
CU_JNS (int cell_number)
{
  int value;
  sc_accumulatorGet (&value);
  if (((value >> 14) == 0) && (value & 0x3fff) != 0)
    {
      sc_icounterSet (cell_number);
    }
}

void
CU ()
{
  int sign = 0;
  int operand = 0;
  int command = 0;
  int icounter = 0;
  int value = 0;

  sc_icounterGet (&icounter);
  sc_setIgnoreCache (0);

  int code = sc_memoryGet (icounter, &value);
  if (code == -1)
    {
      sc_regSet (OUTMEM, 1);
      sc_regSet (IGNORE_INTERRUPT, 1);
      return;
    }
  if (code == -2)
    {
      return;
    }

  if (sc_commandDecode (value, &sign, &command, &operand) == -1)
    {
      sc_regSet (WRONG_COMMAND, 1);
      sc_regSet (IGNORE_INTERRUPT, 1);
      return;
    }
  if (sc_commandValidate (command) == -1 || sign == 1)
    {
      sc_regSet (WRONG_COMMAND, 1);
      sc_regSet (IGNORE_INTERRUPT, 1);
      return;
    }

  int ret;
  switch (command)
    {
    case NOP:
      break;
    case CPUINFO:
      CU_CPUINFO ();
      break;
    case READ:
      CU_READ (operand);
      break;
    case WRITE:
      CU_WRITE (operand);
      break;
    case LOAD:
      if (CU_LOAD (operand) == -2)
        return;
      break;
    case STORE:
      if (CU_STORE (operand) == -2)
        return;
      break;
    case JUMP:
      CU_JUMP (operand);
      break;
    case JNEG:
      CU_JNEG (operand);
      break;
    case JZ:
      CU_JZ (operand);
      break;
    case HALT:
      CU_HALT (operand);
      break;
    case JNS:
      CU_JNS (operand);
      break;
    default:
      ret = ALU (command, operand);
      if (ret == -3)
        {
          return;
        }

      sc_accumulatorSet (ret);
      break;
    }

  int newcmd = 0;
  sc_icounterGet (&newcmd);
  if (newcmd == icounter)
    {
      if (sc_icounterSet (icounter + 1))
        {
          sc_regSet (IGNORE_INTERRUPT, 1);
        }
    }
}