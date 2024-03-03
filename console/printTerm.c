#include <unistd.h>
#include <string.h>

#include "mySimpleComputer.h"
#include "myTerm.h"

void printTerm (int address, int input)
{
    static char slider[5][10] = {0};
    int value = 0;
    int sign = 0;
    int command = 0;
    int operand = 0;

    for (int i = 3; i >= 0; i--)
    {
        strcpy(slider[i+1], slider[i]);
    }
    
    if (input == 1)
    {
        snprintf(slider[0], 10, "%.2x>", address);
    }
    else
    {
        sc_memoryGet(address, &value);
        sc_commandDecode (value, &sign, &command, &operand);
        snprintf(slider[0], 10, "%.2x> %.2x%.2x", address, command, operand);
    }
    
    for (int i = 0; i < 5; i++)
    {
        mt_gotoXY(65, 20 + i);
        write(STDOUT_FILENO, slider[i], 10);
    }
}