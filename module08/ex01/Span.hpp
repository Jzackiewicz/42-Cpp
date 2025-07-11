#pragma once
#include <algorithm>
#include <vector>
#include <stdexcept>
#include <iostream>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void addNumber(int number);
		void addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end);
		unsigned int shortestSpan(void) const;
		unsigned int longestSpan(void) const;
};