#pragma once
#include <algorithm>
#include <vector>

class Span
{
	private:
		std::vector<int>	_numbers;
		unsigned int		_maxSize;

	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);
		template <typename T>
		void addNumbers(T begin, T end);

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
};