#include "PmergeMe.hpp"
#include <iostream>
#include <exception>
#include <ctime>

int	main(int argc, char **argv)
{
	try
	{
		PmergeMe pmergeMe(argc, argv);
		std::cout << "Before: ";
		pmergeMe.printNumbers(VECTOR);
		double vecTime = pmergeMe.sortAndMeasure(VECTOR);
		double lstTime = pmergeMe.sortAndMeasure(LIST);
		std::cout << "After: ";
		pmergeMe.printNumbers(VECTOR);
		pmergeMe.printTime(VECTOR, vecTime);
		pmergeMe.printTime(LIST, lstTime);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}