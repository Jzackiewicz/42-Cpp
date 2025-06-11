#include "Swap.hpp"

bool checkInput(std::string filename, std::string s1)
{
    if (filename.empty() || s1.empty())
    {
        std::cerr << "Filename and s1 cannot be empty!" << std::endl;
        return false;
    }

    std::ifstream file(filename.c_str());
    if (!file.good())
    {
        std::cerr << "File not found or cannot be opened!" << std::endl;
        return false;
    }
    if (file.peek() == std::ifstream::traits_type::eof())
    {
        std::cerr << "File is empty!" << std::endl;
        return false;
    }
    file.close();
    return true;
}

void findAndReplace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream inputFile(filename.c_str());
    std::ofstream outputFile((filename + ".replace").c_str());
    std::string text;

    while (getline(inputFile, text))
    {
        if (text == s1)
            outputFile << s2 << std::endl;
        else
            outputFile << text << std::endl;
    }
    inputFile.close();
    outputFile.close();
}
