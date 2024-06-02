#pragma once
#include <string>
#include <unordered_map>

#include "parser.hpp"

namespace SA
{
    class Translator
    {
    private:
        std::unordered_map<std::string, int> commands;
        SA::Parser parser;
        std::string inputfile;
        std::string outputfile;

    public:
        Translator(int argc, const char* argv[]);
        ~Translator();

    public:
        bool isCanBeCompiled() const;

        void compile();
    };
} // namespace SA
