#include <stdio.h>

#include <mySimpleComputer.h>

enum {SIZEMEM = 128};

int MEM[SIZEMEM];

void sc_memoryInit()
{
    for (int i = 0; i < SIZEMEM; i++)
    {
        MEM[i] = 0; 
    }
}

int sc_memorySet(int address, int value)
{
    if (!(address >= 0 && address < SIZEMEM))
    {
        return 0;
    }
    
    MEM[address] = value;
    return 1;
}

int sc_memoryGet(int address, int * value)
{
    if (!(address >= 0 && address < SIZEMEM))
    {
        return 0;
    }
    
    *value = MEM[address];
    return 1;
}

int main()
{

    return 0;
}