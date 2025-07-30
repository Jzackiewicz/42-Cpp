#include "PmergeMe.hpp"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include <sstream>
#include <limits>

PmergeMe::PmergeMe(int argc, char **argv)
{
	this->parseArguments(argc, argv);
	std::cout << "Before: ";
	this->printNumbers("Vector");
	this->_vec = this->sortVector(this->_vec);
	std::cout << std::endl << "After: ";
	this->printNumbers("Vector");
	std::cout << std::endl;
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vec = other._vec;
	this->_deq = other._deq;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_deq = other._deq;
	}
	return (*this);
}

int	PmergeMe::loadArgument(const std::string &arg)
{
	long value;
	char *endptr;

	Validator::isNumber(arg);
	value = std::strtol(arg.c_str(), &endptr, 10);
	Validator::isINT(value, endptr);
	Validator::isDuplicate(static_cast<int>(value), this->_vec);
	Validator::isDuplicate(static_cast<int>(value), this->_deq);
	return (static_cast<int>(value));

}

void PmergeMe::parseArguments(int argc, char **argv)
{
	int	value;

	if (argc < 2)
	{
		throw std::invalid_argument("No arguments provided.");
	}
	for (int i = 1; i < argc; ++i)
	{
		value = this->loadArgument(argv[i]);
		this->_vec.push_back(value);
		this->_deq.push_back(value);
	}
}

void PmergeMe::printNumbers(const std::string &containerName) const
{
	std::vector<int>::const_iterator vecIt;
	std::deque<int>::const_iterator deqIt;

	if (containerName == "vector")
	{
		for (vecIt = this->_vec.begin(); vecIt != this->_vec.end(); ++vecIt)
		{
			std::cout << *vecIt << " ";
		}
	}
	else
	{
		for (deqIt = this->_deq.begin(); deqIt != this->_deq.end(); ++deqIt)
		{
			std::cout << *deqIt << " ";
		}
	}
}

int	PmergeMe::getJacobsthalNum(int n)
{
	if (n < 0)
	{
		throw std::invalid_argument("Negative index for Jacobsthal number.");
	}
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return getJacobsthalNum(n - 1) + 2 * getJacobsthalNum(n - 2);
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> &input)
{
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	if (input.size() < 2)
	{
		return input;
	}
	for (size_t i = 0; i + 1 < input.size(); i += 2)
	{
		if (input[i] > input[i + 1])
		{
			mainChain.push_back(input[i]);
			pendChain.push_back(input[i + 1]);
		}
		else
		{
			mainChain.push_back(input[i + 1]);
			pendChain.push_back(input[i]);
		}
	}
	if (input.size() % 2 != 0)
		pendChain.push_back(input.back());
	std::vector<int> sorted = sortVector(mainChain);
	return sorted;
}

Validator::Validator() {}

Validator::~Validator() {}

Validator::Validator(const Validator &) {}

Validator &Validator::operator=(const Validator &)
{
	return *this;
}

void Validator::isNumber(const std::string &arg)
{
	for (size_t i = 0; i < arg.size(); i++)
	{
		if (!std::isdigit(arg[i]))
		{
			throw std::invalid_argument("Invalid argument: " + arg);
		}
	}
}

void Validator::isINT(long value, char *endptr)
{
	std::ostringstream oss;

	oss << value;
	if (*endptr != '\0' || value < 0)
	{
		throw std::invalid_argument("Invalid argument: " + oss.str());
	}
	if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
	{
		throw std::out_of_range("Value out of range: " + oss.str());
	}
}
