#pragma once

#include <string>
#include <vector>

namespace SB
{
    class Parser
    {
    private:
        std::vector<std::string> args;

    public:
        Parser(int argc, const char* argv[]);
        ~Parser();

        const std::string getOutputFilename() const;
        const std::string getInputFilename() const;

        std::vector<std::string> readFile(const std::string& filename);
        std::vector<std::string> getTokens(const std::string& str);

        void printError(const std::string &str, int index);
    };
    



} // namespace SB
