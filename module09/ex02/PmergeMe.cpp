#include "PmergeMe.hpp"


PmergeMe::PmergeMe(int argc, char **argv)
{
	this->parseArguments(argc, argv);
}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	this->_vec = other._vec;
	this->_lst = other._lst;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_vec = other._vec;
		this->_lst = other._lst;
	}
	return (*this);
}

double	PmergeMe::sortAndMeasure(ContainerType type)
{
	clock_t		start, end;
	double		timeTaken;

	start = clock();
	if (type == VECTOR)
		this->_vec = this->sortVector(this->_vec);
	else if (type == LIST)
		this->_lst = this->sortList(this->_lst);
	end = clock();

	timeTaken = 1000000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
	return (timeTaken);
}

void	PmergeMe::printTime(ContainerType type, double timeTaken) const
{
	std::string containerName = (type == VECTOR) ? "std::vector" : "std::list";
	std::cout << "Time to process a range of " << ((type == VECTOR) ? this->_vec.size() : this->_lst.size())
			  << " elements with " << containerName << ": " << timeTaken << " us" << std::endl;
}

void	PmergeMe::loadArgument(const std::string &arg)
{
	long value;
	char *endptr;

	Validator::isNumber(arg);
	value = std::strtol(arg.c_str(), &endptr, 10);
	Validator::isINT(value, endptr);
	Validator::isDuplicate(static_cast<int>(value), this->_vec);
	Validator::isDuplicate(static_cast<int>(value), this->_lst);
	this->_vec.push_back(static_cast<int>(value));
	this->_lst.push_back(static_cast<int>(value));
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

void PmergeMe::printNumbers(ContainerType type) const
{
	std::vector<int>::const_iterator	vecIt;
	std::list<int>::const_iterator		lstIt;
	int 								count = 0;
	
	if (type == VECTOR)
	{
		for (vecIt = this->_vec.begin(); vecIt != this->_vec.end(); ++vecIt)
		{
			std::cout << *vecIt << " ";
			count++;
			if (count == 5)
			{
				std::cout << "[...]";
				break;
			}
		}
	}
	else
	{
		for (lstIt = this->_lst.begin(); lstIt != this->_lst.end(); ++lstIt)
		{
			std::cout << *lstIt << " ";
			count++;
			if (count == 5)
			{
				std::cout << "[...]";
				break;
			}
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
		return (input);
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

std::list<int> PmergeMe::sortList(std::list<int> &input)
{
    std::list<int> mainChain;
    std::list<int> pendChain;

    if (input.size() < 2)
        return input;
    std::list<int>::iterator it = input.begin();
    while (it != input.end())
    {
        std::list<int>::iterator next = it;
        ++next;
        if (next != input.end())
        {
            if (*it > *next)
            {
                mainChain.push_back(*it);
                pendChain.push_back(*next);
            }
            else
            {
                mainChain.push_back(*next);
                pendChain.push_back(*it);
            }
            ++it;
            ++it;
        }
        else
        {
            pendChain.push_back(*it);
            break;
        }
    }

    mainChain = sortList(mainChain);
    insertPendChainList(mainChain, pendChain);
    return (mainChain);
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

void	PmergeMe::insertPendChainList(std::list<int> &mainChain, std::list<int> &pendChain)
{
    std::vector<int> order = this->getJacobsthalOrder(pendChain.size());

    for (std::vector<int>::size_type i = 0; i < order.size(); ++i)
    {
        std::list<int>::iterator pit = pendChain.begin();
        for (int j = 0; j < order[i]; ++j)
            ++pit;

        int value = *pit;

        std::list<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), value);

        mainChain.insert(it, value);
    }
}

Validator::Validator() {}

Validator::~Validator() {}

Validator::Validator(const Validator &) {}

Validator &Validator::operator=(const Validator &)
{
	return (*this);
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
