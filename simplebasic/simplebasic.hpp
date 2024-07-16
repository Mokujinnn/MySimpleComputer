#pragma once
#include <iostream>
#include <unordered_set>

#include "simpleassembler.hpp"
#include "parser.hpp"

namespace SB
{
    class Compiler
    {
    private:
        SB::Parser parser;
        std::unordered_map<std::string, bool (*)(Compiler *, std::vector<std::string>&, std::vector<std::string>&)> keywords;
        std::unordered_map<std::string, int> variables;
        std::unordered_map<std::string, int> constants;

        std::string outputfile;
        std::string inputfile;

        int curpos;
        int varpos;
    public:

        Compiler(int argc, const char* argv[]);
        ~Compiler();

        bool isCanBeCopiled();
        void compile();

    private:
        static bool REM(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
        static bool INPUT(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
        static bool OUTPUT(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);

        friend void LET_calc(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens, std::string& rvalue);
        static bool LET(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
        static bool IF(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
        static bool GOTO(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
        static bool END(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens);
    };


} // namespace SB
