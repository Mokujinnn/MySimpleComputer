#include <stdio.h>
#include <inttypes.h>

int sc_commandEncode(int sign, int command, int operand, int * value)
{
    if (!value || !(sign == 1 || sign == 0) || !(command >= 0 && command <= 0x07ff) || !(operand >= 0 && operand <= 0x07ff))
    {
        return -1;
    }
    
    *value = ((command << 8) | (sign << 15)) | operand;

    return 0;
}

int main()
{

    int value = 0;

    sc_commandEncode(1, 15, 16, &value);

    printf("%d\n", value);

    return 0;
}