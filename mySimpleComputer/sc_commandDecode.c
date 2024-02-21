int
sc_commandDecode (int value, int *sign, int *command, int *operand)
{
  if (!sign || !command || !operand)
    {
      return -1;
    }

  *sign = value >> 14;
  *command = (value >> 7) & 0x7f;
  *operand = value & 0x7f;

  return 0;
}