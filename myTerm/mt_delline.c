#include <unistd.h>

int mt_delline()
{
    write(STDOUT_FILENO, "\E[M", 4);
    return 0;
}