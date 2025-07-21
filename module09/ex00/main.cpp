#include <iostream>
#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2)
    {
        std::cerr << "Usage: ./btc <input_file>" << std::endl;
        return (1);
    }
	BitcoinExchange bitEx(argv[1]);

	bitEx._calculateValues()
	return (0);
}