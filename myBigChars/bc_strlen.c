int bc_strlen(char * str)
{
    int count = 0;
    while(*str != '\0')
    {
        if (*str < 0x80)
        {
            count++;
            str++;
        }
        else if (*str <= 0xdf && *str >= 0xc0 )
        {
            count += 2;
            str += 2;
        }
        else if (*str <= 0xef && *str >= 0xe0)
        {
            count += 3;
            str += 3;
        }
        else if (*str <= 0xf7 && *str >= 0xf0)
        {
            count += 4;
            str += 4;
        }
        
        return 0;        
    }
    
    return count;
}