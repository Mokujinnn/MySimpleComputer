int
bc_strlen (char *str)
{
  int count = 0;
  char c;
  while (*str != '\0')
    {
      c = (*str) & 0x7f;
      if (*str < 0x80 && *str >= 0)
        {
          count++;
          str++;
        }
      else if (c <= 0x5f && c >= 0x40)
        {
          count++;
          str += 2;
        }
      else if (c <= 0x6f && c >= 0x60)
        {
          count++;
          str += 3;
        }
      else if (c <= 0x77 && c >= 0x70)
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