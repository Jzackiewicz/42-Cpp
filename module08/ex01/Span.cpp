#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <climits>
#include <vector>
#include <iterator>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        this->_numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return (*this);
}

Span::~Span() {}

void Span::addNumber(int number)
{
    try
    {
        if (this->_numbers.size() >= this->_maxSize)
            throw (std::runtime_error("Span is full, cannot add more numbers"));
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
    this->_numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
    std::size_t rangeSize = std::distance(begin, end);
    if (rangeSize + this->_numbers.size() > this->_maxSize)
    {
        std::cerr << "Adding these numbers exceeds the maximum size of the Span" << std::endl;
        return;
    }
    this->_numbers.insert(this->_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
    try
    {
        {
            if (this->_numbers.size() < 2)
                throw std::runtime_error("Not enough numbers to find a span");
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    std::vector<int> sortedNumbers = this->_numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    unsigned int minSpan = UINT_MAX;
    for (size_t i = 1; i < sortedNumbers.size(); ++i)
    {
        unsigned int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

unsigned int Span::longestSpan() const
{
    try
    {
        if (this->_numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to find a span");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
        exit(EXIT_FAILURE);
    }

    std::vector<int>::const_iterator minIt = std::min_element(this->_numbers.begin(), this->_numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(this->_numbers.begin(), this->_numbers.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}