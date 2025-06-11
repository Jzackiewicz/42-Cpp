#include "Swap.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Invalid arguments!" << std::endl
                  << "./swap <filename> <s1> <s2>" << std::endl;
        return (1);
    }
    if (!checkInput(argv[1], argv[2]))
        return (1);
    findAndReplace(argv[1], argv[2], argv[3]);
    return (0);
}