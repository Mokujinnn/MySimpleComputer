#include <stdio.h>

#include "myReadKey.h"

int main(int argc, char const *argv[])
{
    enum keys key;
    rk_mytermsave();
    rk_mytermregime(0, 10, 3, 0, 0);
    rk_readkey(&key);
    printf("%d\n", key);

    // while (1)
    // {
    //     rk_readkey(&key);
    //     printf("%d\n", key);
    // }

    // rk_readkey(&key);

    // rk_mytermrestore();
    return 0;
}
