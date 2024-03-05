#include <unistd.h>

#include "mySimpleComputer.h"

void printCommand ()
{
    int value = 0;
    int sign = 0;
    int command = 0;
    int operand = 0;

    sc_icounterGet(&value);
    sc_commandDecode(value, &sign, &command, &operand);


}