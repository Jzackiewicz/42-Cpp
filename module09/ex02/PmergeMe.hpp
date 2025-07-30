#pragma once

#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <sstream>

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		int			loadArgument(const std::string &arg);
		void		parseArguments(int argc, char **argv);
		
		static int	getJacobsthalNum(int n);
	
	public:
		PmergeMe(int argc, char **argv);
		~PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);

		std::vector<int>	sortVector(std::vector<int> &input);
		void sortDeque();
		void printNumbers(const std::string &containerName) const;
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