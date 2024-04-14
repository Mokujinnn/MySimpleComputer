#include <stdio.h>

#include "myReadKey.h"

int main(int argc, char const *argv[])
{
    // enum keys key;
    // while (1)
    // {
    //     rk_readkey(&key);

    //     printf("%d\n", key);
    // }

    // rk_mytermsave();
    if (rk_mytermrestore() == 0)
    {
        printf("%d\n", 1);
    }
    

    return 0;
}
