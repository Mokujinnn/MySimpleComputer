#include "mySimpleComputer.h"
#include "myTerm.h"
#include <unistd.h>

void printCache()
{
    int address;
    int cacheline[10];
    

    for (int i = 0; i < CACHESIZE; i++)
    {
        address = sc_getCacheLine(i, cacheline);
        char buf[64] = {0};
        
        if (address == -1)
        {
            continue;
        }
        
        mt_gotoXY(2, 20 + i);
        snprintf(buf, 63, "%d: ", address);
        write(STDOUT_FILENO, buf, 63);

        for (int j = 0; j < (address == 120 ? 8 : 10); j++)
        {
            int sign, command, operand;
            sc_commandDecode(cacheline[j], &sign, &command, &operand);

            mt_gotoXY(j * 6 + 7, 20 + i);

            if (sign)
            {
                snprintf(buf, 2, "-");
            }
            else
            {
                snprintf(buf, 2, "+");
            }

            snprintf(&buf[1], 5, "%.2x%.2x", command, operand);
            write(STDOUT_FILENO, buf, 5);
        }
    }
}