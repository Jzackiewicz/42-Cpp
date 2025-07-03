#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter
{
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);

		static void convert(const std::string &literal);
};

bool	isNumber(const std::string &literal);
void	printChar(const std::string &literal);
void	printInt(const std::string &literal);
void	printFloat(const std::string &literal);
void	printDouble(const std::string &literal);