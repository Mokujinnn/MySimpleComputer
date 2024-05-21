int
sc_commandValidate (int command)
{
  if (command >= 0 && command <= 0x4c)
    {
      return 0;
    }

  return -1;
}