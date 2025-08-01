#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <ctime>

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeMe(argc, argv);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}