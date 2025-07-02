#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(const std::string &literal)
{
	std::stringstream	inputStream(literal);
	// int					intResult;
	float				floatResult;
	// double	doubleResult;
	// char	charResult;
	
	inputStream >> floatResult;
	if (inputStream.fail() || !inputStream.eof())
		std::cout << "Int: Impossible" << std::endl;
	else
		std::cout << "Int: " << static_cast<int>(floatResult) << std::endl;
	// std::cout << "Int: " << intResult << std::endl;
}
