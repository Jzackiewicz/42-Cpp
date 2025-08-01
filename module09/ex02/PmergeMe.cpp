#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv)
{
	clock_t start, end;
	double timeTakenVec, timeTakenDeq;


	this->parseArguments(argc, argv);
	std::cout << "Before: ";
	this->printNumbers("vector");
	start = clock();

	this->_vec = this->sortVector(this->_vec);
	end = clock();
	timeTakenVec = 10000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;

	start = clock();
	this->_deq = this->sortDeque(this->_deq);
	end = clock();
	timeTakenDeq = 10000 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
	
	std::cout << std::endl << "After: ";
	this->printNumbers("vector");

	std::cout << "Time to process a range of " << this->_vec.size() << " elements with std::vector: "
			  << timeTakenVec << " us" << std::endl;
	std::cout << "Time to process a range of " << this->_deq.size() << " elements with std::deque: "
			  << timeTakenDeq << " us" << std::endl;
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

void	PmergeMe::loadArgument(const std::string &arg)
{
	long value;
	char *endptr;

	Validator::isNumber(arg);
	value = std::strtol(arg.c_str(), &endptr, 10);
	Validator::isINT(value, endptr);
	Validator::isDuplicate(static_cast<int>(value), this->_vec);
	Validator::isDuplicate(static_cast<int>(value), this->_deq);
	this->_vec.push_back(static_cast<int>(value));
	this->_deq.push_back(static_cast<int>(value));
}

void PmergeMe::parseArguments(int argc, char **argv)
{
	if (argc < 2)
	{
		throw std::invalid_argument("No arguments provided.");
	}
	for (int i = 1; i < argc; ++i)
	{
		this->loadArgument(argv[i]);
	}
}

void PmergeMe::printNumbers(const std::string &containerName) const
{
	std::vector<int>::const_iterator	vecIt;
	std::deque<int>::const_iterator		deqIt;

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
	std::cout << std::endl;
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

std::vector<int> PmergeMe::getJacobsthalOrder(int size)
{
	std::vector<int>	order;
	int					jacobsthalNum;

	for (int i = 3; ; i++)
	{
		jacobsthalNum = this->getJacobsthalNum(i);
		if (jacobsthalNum > size || jacobsthalNum == 0)
			break;
		order.push_back(jacobsthalNum - 1);
	}
	for (int i = 0; i < size; i++)
	{
		if (std::find(order.begin(), order.end(), i) == order.end())
		{
			order.push_back(i);
		}
	}
	return (order);
}

std::vector<int>	PmergeMe::sortVector(std::vector<int> &input)
{
	std::vector<int> mainChain;
	std::vector<int> pendChain;

	if (input.size() < 2)
	{
		return (input);
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
	this->insertPendChainVector(sorted, pendChain);
	return (sorted);
}

std::deque<int> PmergeMe::sortDeque(std::deque<int> &input)
{
	std::deque<int> mainChain;
	std::deque<int> pendChain;

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
	std::deque<int> sorted = sortDeque(mainChain);
	this->insertPendChainDeque(sorted, pendChain);
	return (sorted);
}

void	PmergeMe::insertPendChainVector(std::vector<int> &mainChain, std::vector<int> &pendChain)
{
	mainChain.reserve(mainChain.size() + pendChain.size());
	std::vector<int> order = this->getJacobsthalOrder(pendChain.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int value = pendChain[order[i]];
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
		mainChain.insert(it, value);
	}
}

void	PmergeMe::insertPendChainDeque(std::deque<int> &mainChain, std::deque<int> &pendChain)
{
        std::vector<int> order = this->getJacobsthalOrder(pendChain.size());

        for (size_t i = 0; i < order.size(); ++i) {
            int value = pendChain[order[i]];
            std::deque<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);
            mainChain.insert(it, value);
        }
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
