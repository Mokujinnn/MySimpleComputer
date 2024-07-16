#include "simplebasic.hpp"

#include <algorithm>
#include <strstream>
#include <iomanip>
#include <fstream>

namespace SB
{
    bool Compiler::REM(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        return true;
    }

    bool Compiler::INPUT(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        assemblycode[cl->curpos] = std::to_string(cl->curpos) + " READ " + std::to_string(cl->varpos) + " " + tokens[0];
        cl->variables.emplace(tokens[2], cl->varpos);
        cl->curpos++;
        cl->varpos--;
        return true;
    }

    bool Compiler::OUTPUT(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        assemblycode[cl->curpos] = std::to_string(cl->curpos) + " WRITE " + std::to_string(cl->variables[tokens[2]]) + " " + tokens[0];
        cl->curpos++;
        return true;
    }

    std::string toHex(int i)
    {
        char buf[10];
        if (i < 0)
        {
            buf[0] = '-';
            i -= 2 * i;
        }
        else
        {
            buf[0] = '+';
        }

        snprintf(&buf[1], 5, "%.4x", i);

        return std::string(buf);
    }

    void LET_calc(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens, std::string &rvalue)
    {
        rvalue.pop_back();
        size_t ret = rvalue.find_first_of("*/+-");
        if (ret == std::string::npos)
        {
            auto it = cl->variables.find(rvalue); // ищем переменную
            if (it == cl->variables.end()) // если не нашел переменную
            {
                if (cl->constants.find(rvalue) == cl->constants.end()) // если не нашел константу
                {
                    cl->constants.emplace(rvalue, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(rvalue));
                    cl->varpos--;
                }
                
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[rvalue]) + " " + tokens[0];
                cl->curpos++;
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
                cl->curpos++;
            }
            else // нашли переменную
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
                cl->curpos++;
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
                cl->curpos++;
            }
        }
        else if (rvalue[ret] == '*')
        {
            auto left = tokens.begin();
            auto right = tokens.begin();
            for (auto it = tokens.begin(); it != tokens.end(); ++it)
            {
                if (*it == "*")
                {
                    left = it - 1;
                    right = it + 1;
                    break;
                }
            }

            auto it = cl->variables.find(*left);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*left) == cl->constants.end())
                {
                    cl->constants.emplace(*left, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*left));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[*left]) + " " + tokens[0];
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
                cl->curpos++;
            }

            it = cl->variables.find(*right);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*right) == cl->constants.end())
                {
                    cl->constants.emplace(*right, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*right));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " MUL " + std::to_string(cl->constants[*right]);
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " MUL " + std::to_string((*it).second);
                cl->curpos++;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
            cl->curpos++;
        }
        else if (rvalue[ret] == '/')
        {
            auto left = tokens.begin();
            auto right = tokens.begin();
            for (auto it = tokens.begin(); it != tokens.end(); ++it)
            {
                if (*it == "/")
                {
                    left = it - 1;
                    right = it + 1;
                    break;
                }
            }

            auto it = cl->variables.find(*left);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*left) == cl->constants.end())
                {
                    cl->constants.emplace(*left, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*left));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[*left]) + " " + tokens[0];
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
                cl->curpos++;
            }

            it = cl->variables.find(*right);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*right) == cl->constants.end())
                {
                    cl->constants.emplace(*right, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*right));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " DIVIDE " + std::to_string(cl->constants[*right]);
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " DIVIDE " + std::to_string((*it).second);
                cl->curpos++;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
            cl->curpos++;
        }
        else if (rvalue[ret] == '+')
        {
            auto left = tokens.begin();
            auto right = tokens.begin();
            for (auto it = tokens.begin(); it != tokens.end(); ++it)
            {
                if (*it == "+")
                {
                    left = it - 1;
                    right = it + 1;
                    break;
                }
            }

            auto it = cl->variables.find(*left);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*left) == cl->constants.end())
                {
                    cl->constants.emplace(*left, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*left));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[*left]) + " " + tokens[0];
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
                cl->curpos++;
            }

            it = cl->variables.find(*right);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*right) == cl->constants.end())
                {
                    cl->constants.emplace(*right, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*right));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " ADD " + std::to_string(cl->constants[*right]);
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " ADD " + std::to_string((*it).second);
                cl->curpos++;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
            cl->curpos++;
        }
        else if (rvalue[ret] == '-')
        {
            auto left = tokens.begin();
            auto right = tokens.begin();
            for (auto it = tokens.begin(); it != tokens.end(); ++it)
            {
                if (*it == "-")
                {
                    left = it - 1;
                    right = it + 1;
                    break;
                }
            }

            auto it = cl->variables.find(*left);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*left) == cl->constants.end())
                {
                    cl->constants.emplace(*left, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*left));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[*left]) + " " + tokens[0];
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
                cl->curpos++;
            }

            it = cl->variables.find(*right);
            if (it == cl->variables.end())
            {
                if (cl->constants.find(*right) == cl->constants.end())
                {
                    cl->constants.emplace(*right, cl->varpos);
                    assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*right));
                    cl->varpos--;
                }

                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " SUB " + std::to_string(cl->constants[*right]);
                cl->curpos++;
            }
            else
            {
                assemblycode[cl->curpos] = std::to_string(cl->curpos) + " SUB " + std::to_string((*it).second);
                cl->curpos++;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " STORE " + std::to_string(cl->variables[tokens[2]]);
            cl->curpos++;
        }
    }

    bool Compiler::LET(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        std::string rvalue;
        auto it = cl->variables.find(tokens[2]);

        if (it == cl->variables.end())
        {
            cl->variables.emplace(tokens[2], cl->varpos);
            cl->varpos--;
        }

        for (int i = 4; i < tokens.size(); ++i)
        {
            rvalue += tokens[i] + " ";
        }

        LET_calc(cl, assemblycode, tokens, rvalue);

        return true;
    }

    bool Compiler::IF(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        std::vector<std::string> compare_signs = {">", "<", ">=", "<=", "=="};
        std::string sign;
        auto left = tokens.begin();
        auto right = tokens.begin();

        for (auto it = tokens.begin(); it != tokens.end(); ++it)
        {
            bool breakflag = false;
            for (int i = 0; i < compare_signs.size(); ++i)
            {
                if (*it == compare_signs[i])
                {
                    sign = *it;
                    left = it - 1;
                    right = it + 1;
                    breakflag = true;
                    break;
                }
            }

            if (breakflag)
                break;
        }

        auto it = cl->variables.find(*left);
        if (it == cl->variables.end())
        {
            if (cl->constants.find(*left) == cl->constants.end())
            {
                cl->constants.emplace(*left, cl->varpos);
                assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*left));
                cl->varpos--;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string(cl->constants[*left]) + " " + tokens[0];
            cl->curpos++;
        }
        else
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " LOAD " + std::to_string((*it).second) + " " + tokens[0];
            cl->curpos++;
        }

        it = cl->variables.find(*right);
        if (it == cl->variables.end())
        {
            if (cl->constants.find(*right) == cl->constants.end())
            {
                cl->constants.emplace(*right, cl->varpos);
                assemblycode[cl->varpos] = std::to_string(cl->varpos) + " = " + toHex(std::stoi(*right));
                cl->varpos--;
            }

            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " SUB " + std::to_string(cl->constants[*right]);
            cl->curpos++;
        }
        else
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " SUB " + std::to_string((*it).second);
            cl->curpos++;
        }

        if (sign == ">")
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JZ " + std::to_string(std::stoi(tokens[0]) + 10); 
            cl->curpos++;
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNEG " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
        }
        else if (sign == "<")
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JZ " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNS " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
        }
        else if (sign == ">=")
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNEG " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
        }
        else if (sign == "<=")
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNS " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
        }
        else if (sign == "==")
        {
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNEG " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
            assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JNS " + std::to_string(std::stoi(tokens[0]) + 10);
            cl->curpos++;
        }

        auto it1 = cl->keywords.find(*(++right));
        auto newtokens = std::vector<std::string>(right, tokens.end());
        newtokens.insert(newtokens.begin(), tokens[0]);

        (*it1).second(cl, assemblycode, newtokens);

        int index = assemblycode[cl->curpos - 1].rfind(' ');
        assemblycode[cl->curpos - 1].erase(index);

        return true;
    }

    bool Compiler::GOTO(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        assemblycode[cl->curpos] = std::to_string(cl->curpos) + " JUMP " + tokens[2] + " " + tokens[0];
        cl->curpos++;

        return true;
    }

    bool Compiler::END(Compiler *cl, std::vector<std::string> &assemblycode, std::vector<std::string> &tokens)
    {
        assemblycode[cl->curpos] = std::to_string(cl->curpos) + " HALT 00 " + tokens[0];
        cl->curpos++;

        return true;
    }

    bool isStringDigit(const std::string &str)
    {
        return !(str.size() - std::count_if(str.begin(), str.end(), [](unsigned char c)
                                            { return std::isdigit(c); }));
    }

    Compiler::Compiler(int argc, const char *argv[])
        : parser(argc, argv),
          curpos(0),
          varpos(127),
          inputfile(parser.getInputFilename()),
          outputfile(parser.getOutputFilename())
    {
        keywords.emplace("REM", REM);
        keywords.emplace("INPUT", INPUT);
        keywords.emplace("OUTPUT", OUTPUT);
        keywords.emplace("LET", LET);
        keywords.emplace("IF", IF);
        keywords.emplace("GOTO", GOTO);
        keywords.emplace("END", END);
    }

    Compiler::~Compiler()
    {
    }

    bool Compiler::isCanBeCopiled()
    {
        return !(inputfile.empty() || outputfile.empty());
    }

    void Compiler::compile()
    {
        std::vector<std::string> file = parser.readFile(inputfile);

        if (file.empty())
        {
            std::cout << "Cant open file " << inputfile << '\n';
            return;
        }

        std::vector<std::string> assemblycode(128);

        for (auto &&i : file)
        {
            std::vector<std::string> tokens = parser.getTokens(i);

            if (!isStringDigit(tokens[0]))
            {
                parser.printError(i, 1);
                return;
            }

            auto it = keywords.find(tokens[1]);

            if (it == keywords.end())
            {
                parser.printError(i, 4);
                return;
            }

            if (!(*it).second(this, assemblycode, tokens))
            {
                parser.printError(i, 8);
                return;
            }
        }

        for (int i = 127; i >= 0; --i)
        {
            if (assemblycode[i].empty())
            {
                assemblycode.erase(assemblycode.begin() + i);
            }
        }

        int index = 0;
        for (auto &&i : assemblycode)
        {
            for (index = 0; index < i.size(); ++index)
            {
                if (isalpha(i[index]))
                {
                    break;
                }
            }

            int whenreplace = i.find(' ', index);
            std::string str = i.substr(index, whenreplace - index);
            
            if (str == "JZ" || str == "JNEG" || str == "JNS" || str == "JUMP")
            {
                std::string go = i.substr(whenreplace + 1, i.find(' ', whenreplace + 1) - whenreplace - 1);
                for (auto &&j : assemblycode)
                {
                    int k = j.rfind(' ');
                    if (isdigit(j[k-1]) && isdigit(j[k-1]))
                    {
                        if (j.substr(k+1) == go)
                        {
                            std::string to = j.substr(0, j.find(' '));

                            i.erase(whenreplace + 1);
                            i += to;
                        }
                    }
                }
            }
        }
        
        for (auto &&i : assemblycode)
        {
            int index = i.rfind(' ');

            if (isdigit(i[index-1]) && isdigit(i[index+1]))
            {
                i.erase(index);
            }
        }

        std::ofstream out(outputfile);

        for (auto &&i : assemblycode)
        {
            out << i << '\n';
        }
        
        out.close();
    }

} // namespace SB
