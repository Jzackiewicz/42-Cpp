#pragma once

#include <iostream>
#include <stdexcept>
#include <string>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		unsigned int	_size;
		T				*_array;

	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &other);
		Array &operator=(const Array &other);
		~Array(void);
		T &operator[](unsigned int index);
		unsigned int size(void) const;
};

#include "Array.tpp"
