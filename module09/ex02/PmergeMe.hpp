#pragma once

#include <vector>
#include <list>
#include <string>
#include <stdexcept>
#include <sstream>
#include <iostream>
#include <cstdlib>
#include <limits>
#include <algorithm>
#include <ctime>
#include <iomanip>

enum ContainerType
{
	VECTOR,
	LIST
};

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::list<int>		_lst;

		void		loadArgument(const std::string &arg);
		void		parseArguments(int argc, char **argv);
		
		static int			getJacobsthalNum(int n);
		std::vector<int>	getJacobsthalOrder(int n);
		void				insertPendChainVector(std::vector<int> &mainChain,
											std::vector<int> &pendChain);
		void				insertPendChainList(std::list<int> &mainChain,
											std::list<int> &pendChain);
	
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<int>	sortVector(std::vector<int> &input);
		std::list<int>		sortList(std::list<int> &input);
		
		double				sortAndMeasure(ContainerType type);
		void				printNumbers(ContainerType type) const;
		void				printTime(ContainerType type, double timeTaken) const;
};

class Validator
{
	private:
		Validator();
		~Validator();
		Validator(const Validator &other);
		Validator &operator=(const Validator &other);

	public:
		static void isNumber(const std::string &arg);
		static void isINT(long value, char *endptr);
		template <typename T>
		static void isDuplicate(int value, const T &container)
		{
			typename T::const_iterator it;
			std::ostringstream oss;

			oss << value;
			for (it = container.begin(); it != container.end(); ++it)
			{
				if (*it == value)
				{
					throw std::invalid_argument("Duplicate value: " + oss.str());
				}
			}
		}

};
