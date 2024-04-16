#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "myReadKey.h"

int main(int argc, char const *argv[])
{
    enum keys key;
    int value;
    // rk_mytermsave();
    // rk_mytermregime(0, 30, 3, 0, 0);
    
    rk_readvalue(&value, 30);

    // rk_mytermrestore();

    return 0;
}
