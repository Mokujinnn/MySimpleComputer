#include "simpleassembler.hpp"

#include <fstream>
#include <iostream>
#include <strstream>

namespace SA
{
    Translator::Translator(int argc, const char *argv[])
        : parser(argc, argv),
          commands({{"NOP",     0},
                    {"CPUINFO", 1},
                    {"READ",    10},
                    {"WRITE",   11},
                    {"LOAD",    20},
                    {"STORE",   21},
                    {"ADD",     30},
                    {"SUB",     31},
                    {"DIVIDE",  32},
                    {"MUL",     33},
                    {"JUMP",    40},
                    {"JNEG",    41},
                    {"JZ",      42},
                    {"HALT",    43},
                    {"NOT",     51},
                    {"AND",     52}}),
          outputfile(parser.getOutputFilename()),
          inputfile(parser.getInputFilename())
    {
    }

    Translator::~Translator()
    {
    }

    bool Translator::isCanBeCompiled() const
    {
        return !(inputfile.empty() || outputfile.empty());
    }

    void Translator::compile()
    {
        std::vector<std::string> file = parser.readFile(inputfile);

        if (file.empty())
        {
            std::cout << "Cant open file " << inputfile << '\n';
        }

        // bool returncode = parser.lexer(file);

        std::ofstream out(outputfile, std::ios::binary);
        std::vector<int> bin(128, 0);

        for (auto &&i : file)
        {
            int address;
            std::string command;
            int value;
            std::strstream stream;
            stream << i;

            stream >> address >> command >> value;

            bin[address] = (commands[command] << 7 | 0 << 14) | value;
        }

        out.write(reinterpret_cast<const char *>(bin.data()), 128 * sizeof(int));
    }

} // namespace SA
