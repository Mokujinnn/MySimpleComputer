#include <string.h>
#include <unistd.h>

#include "myReadKey.h"

int rk_readkey(enum keys *key)
{
    char buf[7];
    int r = read(STDIN_FILENO, buf, 6);
    if (r == -1)
    {
        return -1;
    }

    buf[6] = '\0';

    if (strncmp(buf, "l", 1) == 0)
        *key = L;
    else if (strncmp(buf, "s", 1) == 0)
        *key = S;
    else if (strncmp(buf, "r", 1) == 0)
        *key = R;
    else if (strncmp(buf, "t", 1) == 0)
        *key = T;
    else if (strncmp(buf, "i", 1) == 0)
        *key = I;
    else if (strncmp(buf, "v", 1) == 0)
        *key = V;
    else if (strncmp(buf, "p", 1) == 0)
        *key = P;
    else if (strncmp(buf, "q", 1) == 0)
        *key = Q;
    else if (strncmp(buf, "-", 1) == 0)
        *key = MINUS;
    else if (strncmp(buf, "+", 1) == 0)
        *key = PLUS;
    else if (strncmp(buf, "\E[15~", 5) == 0)
        *key = F5;
    else if (strncmp(buf, "\E[17~", 5) == 0)
        *key = F6;
    else if (strncmp(buf, "\E[A", 3) == 0)
        *key = UP;
    else if (strncmp(buf, "\E[B", 3) == 0)
        *key = DOWN;
    else if (strncmp(buf, "\E[C", 3) == 0)
        *key = RIGHT;
    else if (strncmp(buf, "\E[D", 3) == 0)
        *key = LEFT;
    // else if (strncmp(buf, "^[", 1) == 0)
    //     *key = ESC;
    else
        *key = UNKNOWN;

    return 0;
}