#pragma once
#include <string>
#include <vector>

namespace SA
{
    class Parser
    {
    private:
        std::vector<std::string> args;

    public:
        Parser(int argc, const char* argv[]);
        ~Parser();

    public:
        const std::string getOutputFilename() const;
        const std::string getInputFilename() const;

        std::vector<std::string> readFile(const std::string& filename);
        bool lexer(const std::vector<std::string> &file);
    
    private:
        int checkString(const std::string &str, std::vector<bool> &addresses);
        void printError(const std::string &str, int index);
    };
} // namespace SA
