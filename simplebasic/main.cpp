#include <iostream>
#include <unordered_map>

#include "simpleassembler.hpp"
#include "simplebasic.hpp"

#include <strstream>
#include <iomanip>

int main(int argc, char const *argv[])
{
    SB::Compiler compiler(argc, argv);

    if (!compiler.isCanBeCopiled())
    {
        std::cout << "Wrong output or/and input filename\n";
        return 0;
    }

    compiler.compile();

    return 0;
}