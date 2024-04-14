#include <termios.h>
#include <unistd.h>
#include <stdio.h>

int rk_mytermrestore()
{
    struct termios term;
    FILE * file = fopen("terminalsettings.bin", "rb");

    if (file == NULL || fread(&term, sizeof(term), 1, file) <= 0)
    {
        return -1;
    }
    
    fclose(file);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &term);

    return 0;
}