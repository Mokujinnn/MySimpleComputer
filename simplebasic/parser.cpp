#include "parser.hpp"

#include <fstream>
#include <strstream>
#include <iostream>

namespace SB
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

    const std::string Parser::getInputFilename() const
    {
        for (auto &&i : args)
        {
            if (i.find(".sb") != std::string::npos)
            {
                return i;
            }
        }
        
        return std::string();
    }

    const std::string Parser::getOutputFilename() const
    {
        for (auto i : args)
        {
            int n = i.find(".sb");
            if (n != std::string::npos)
            {
                return i.replace(n, 3, ".sa");
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

    std::vector<std::string> Parser::getTokens(const std::string& str)
    {
        std::strstream stream;
        stream << str;

        std::string token;
        std::vector<std::string> tokens;

        stream >> token;

        while (!token.empty())
        {
            tokens.push_back(token);

            token.clear();
            stream >> token;
        }
        
        return tokens;
    }

    void Parser::printError(const std::string &str, int index)
    {
        std::cout << str << "\n\n";
        std::cout << std::string(index, '-') << '^' << " Error\n";
    }

} // namespace SB
