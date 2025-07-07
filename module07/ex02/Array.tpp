#pragma once

#include <iostream>
#include <string>

template <typename T> class Array
{
	public:
		Array(void);
		Array(unsigned int n);
		Array(const Array &src);
		~Array(void);
		Array &operator=(const Array &obj);
}