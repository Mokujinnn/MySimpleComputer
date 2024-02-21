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