#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(const std::string &literal);
};