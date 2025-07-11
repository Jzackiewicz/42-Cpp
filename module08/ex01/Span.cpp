#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <limits>
#include <vector>
#include <iterator>

Span::Span(unsigned int n) : _maxSize(n) {}

Span::Span(const Span &other) : _numbers(other._numbers), _maxSize(other._maxSize) {}

Span &Span::operator=(const Span &other)
{
    if (this != &other) {
        _numbers = other._numbers;
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
    _numbers.push_back(number);
}

template <typename T>
void Span::addNumbers(T begin, T end)
{
    try
    {
        if (std::distance(begin, end) + _numbers.size() > _maxSize)
            throw (std::runtime_error("Adding these numbers exceeds the maximum size of the Span"));
    }
    catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
    _numbers.insert(_numbers.end(), begin, end);
}

unsigned int Span::shortestSpan() const
{
    try
    {
        {
            if (_numbers.size() < 2)
                throw std::runtime_error("Not enough numbers to find a span");
        }
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<int> sortedNumbers = _numbers;
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
        if (_numbers.size() < 2)
            throw std::runtime_error("Not enough numbers to find a span");
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
    return static_cast<unsigned int>(*maxIt - *minIt);
}