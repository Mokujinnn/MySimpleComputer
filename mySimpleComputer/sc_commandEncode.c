int
sc_commandEncode (int sign, int command, int operand, int *value)
{
  if (!value || !(sign == 1 || sign == 0) || !(command >= 0 && command <= 0x7f)
      || !(operand >= 0 && operand <= 0x7f))
    {
      return -1;
    }

  *value = ((command << 7) | (sign << 14)) | operand;

  return 0;
}