#include "Span.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

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