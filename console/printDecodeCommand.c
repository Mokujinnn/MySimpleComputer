#include <stdio.h>

void printDecodedCommand(int value)
{
    char bin[16];
    char str[60];

    int tmp = value;
    
    for (int i = 0; i < 15; ++i)
    {
        bin[15 - i - 1] = ((tmp >> i) & 1) + '0';
    }
    
    snprintf(str, 60, "dec: %.5d | oct: %.6o | hex: %.4x | bin: %s", value, value, value, bin);

    fwrite(str, 1, 60, stdout);
}