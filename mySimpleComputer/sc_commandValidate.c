int
sc_commandValidate (int command)
{
  if (command >= 0 && command <= 0x7f)
    {
      return 0;
    }

  return -1;
}