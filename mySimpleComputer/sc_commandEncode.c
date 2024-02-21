#include <stdio.h>
#include <inttypes.h>

int sc_commandEncode(int sign, int command, int operand, int * value)
{
    if (!value || !(sign == 1 || sign == 0) || !(command >= 0 && command <= 0x7f) || !(operand >= 0 && operand <= 0x7f))
    {
        return -1;
    }
    
    *value = ((command << 8) | (sign << 15)) | operand;

    return 0;
}

int sc_commandDecode(int value, int * sign, int * command, int * operand)
{
    if (!sign || !command || !operand)
    {
        return -1;
    }

    *sign = value >> 15;
    *command = (value >> 8) & 0x7f;
    *operand = value & 0x7f;

    return 0;
}

int sc_commandValidate(int command)
{
    if (command >= 0 && command <= 0x7f)
    {
        return 0;
    }

    return -1;
}

int main()
{

    int value = 0;
    int operand = 0;
    int command = 0;
    int sign= 0;

    sc_commandEncode(0, 120, 67, &value);

    printf("%d\n", value);

    sc_commandDecode(value, &sign, &command, &operand);

    printf("%d %d %d\n", sign, command, operand);

    return 0;
}