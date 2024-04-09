#include "myBigChars.h"
#include "mySimpleComputer.h"

void printBigCell(int address, int bigchars[18][ARR_SIZE])
{
    int value = 0;
    int sign = 0;
    int command = 0;
    int operand = 0;

    bc_box(62, 7, 111, 18, ForegroundDefault, BackgroundDefault, "CurrentCell", ForegroundDarkRed, ForegroundDefault);

    sc_memoryGet(address, &value);
    sc_commandDecode(value, &sign, &command, &operand);

    if (sign == 1)
    {
        bc_printbigchar(bigchars[16], 65, 9, ForegroundDefault, BackgroundDefault);
    }
    else
    {
        bc_printbigchar(bigchars[17], 65, 9, ForegroundDefault, BackgroundDefault);
    }

    int command1 = command >> 4;
    command = command & 0x0f;

    int operand1 = operand >> 4;
    operand = operand & 0x0f;

    bc_printbigchar(bigchars[command1], 74, 9, ForegroundDefault, BackgroundDefault);
    bc_printbigchar(bigchars[command], 83, 9, ForegroundDefault, BackgroundDefault);
    bc_printbigchar(bigchars[operand1], 92, 9, ForegroundDefault, BackgroundDefault);
    bc_printbigchar(bigchars[operand], 101, 9, ForegroundDefault, BackgroundDefault);
}