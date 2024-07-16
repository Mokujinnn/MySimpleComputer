#include <iostream>
#include <string>

#include "simpleassembler.hpp"

int main(int argc, char const *argv[])
{
    SA::Translator translator(argc, argv);

    if (!translator.isCanBeCompiled())
    {
        std::cout << "Wrong output or/and input filename\n";
        return 0;
    }
    
    translator.compile();

    return 0;
}