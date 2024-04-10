int
bc_strlen (char *str)
{
  int count = 0;
  while (*str != '\0')
    {
      if ((*str) < 0x80 && *str >= 0)
        {
          count++;
          str++;
        }
      else if (((*str) & 0x7f) <= 0x5f && ((*str) & 0x7f) >= 0x40)
        {
          count++;
          str += 2;
        }
      else if (((*str) & 0x7f) <= 0x6f && ((*str) & 0x7f) >= 0x60)
        {
          count++;
          str += 3;
        }
      else if (((*str) & 0x7f) <= 0x77 && ((*str) & 0x7f) >= 0x70)
        {
          count++;
          str += 4;
        }
      else
        {
          return 0;
        }
    }

  return count;
}