#include "parser.hpp"

#include <fstream>
#include <iostream>

namespace SA
{
    Parser::Parser(int argc, const char* argv[])
    {
        args.resize(argc);

        for (int i = 0; i < argc; ++i)
        {
            args[i] = argv[i];
        }
    }

    Parser::~Parser()
    {
    }

    const std::string Parser::getOutputFilename() const
    {
        for (auto &&i : args)
        {
            if (i.find(".o") != std::string::npos)
            {
                return i;
            }
        }
        
        return std::string();
    }

    const std::string Parser::getInputFilename() const
    {
        for (auto &&i : args)
        {
            if (i.find(".sa") != std::string::npos)
            {
                return i;
            }
        }
        
        return std::string();
    }

    std::vector<std::string> Parser::readFile(const std::string& filename)
    {
        std::ifstream file(filename);
        std::vector<std::string> strings;

        if (!file.is_open())
        {
            return std::vector<std::string>();
        }

        strings.reserve(128);

        while (!file.eof())
        {
            std::string line;
            std::getline(file, line);
            
            strings.push_back(line);
        }

        return strings;
    }

    bool Parser::lexer(const std::vector<std::string> &file)
    {
        std::vector<bool> addresses(128, false);
        bool flag = true;
        

        for (auto &&i : file)
        {
            int index = checkString(i, addresses);

            if (index != -1)
            {
                flag = false;
                printError(i, index);
            }
        }

        return flag;
    }

    int Parser::checkString(const std::string &str, std::vector<bool> &addresses)
    {
        // TODO
        return -1;
    }

    void Parser::printError(const std::string &str, int index)
    {
        std::cout << str;
        std::cout << std::string(index, '-') << '^' << '\n';
    }

}
