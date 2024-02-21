#include "mySimpleComputer.h"

void printCell (int address)
{
    int value = 0;
    int sign = 0;
    int command = 0;
    int operand = 0;

    sc_memoryGet(address, &value);
    sc_commandDecode(value, &sign, &command, &operand);

    char c = (sign == 0) ? '+' : '-';

    printf("%c%x%x\n", c, command, operand);
}