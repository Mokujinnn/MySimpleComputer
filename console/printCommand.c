#include <unistd.h>

#include "mySimpleComputer.h"
#include "myTerm.h"

void printCommand ()
{
    int value = 0;
    int sign = 0;
    int command = 0;
    int operand = 0;
    char tmp[11] = "+ ";

    sc_icounterGet(&value);
    sc_commandDecode(value, &sign, &command, &operand);

    if (command < 0 && command > 76) tmp[0] = '!';

    snprintf(&tmp[3], 10, "%.2x : %.2x", command, operand);

    mt_gotoXY(88, 5);
    write(STDOUT_FILENO, tmp, 11);
}