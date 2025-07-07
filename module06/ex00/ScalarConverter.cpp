#include "ScalarConverter.hpp"
#include <sstream>
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

bool	isNumber(const std::string &literal)
{
	int dotCount = 0;

	for (unsigned int i = 0; i < literal.size(); i++)
	{
		if (literal[i] == '-' && i == 0)
			i++;
		if (literal[i] == '.')
		{
			if (dotCount++ > 1)
				return (false);
			i++;
		}
		if (!isdigit(literal[i]))
		{
			if (literal[i] != 'f' || i != literal.size() - 1 || dotCount != 1)
				return (false);
		}
	}
	return (true);
}

void	printChar(const std::string &literal)
{
	int	value = atoi(literal.c_str());

	if (!isNumber(literal) || value > 127 || value < 0)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if (!isprint(value))
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void	printInt(const std::string &literal)
{
	double	value;

	value = atof(literal.c_str());
	if (!isNumber(literal) ||
		value > std::numeric_limits<int>::max() ||
		value < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible" << std::endl;
		return ;
	}
	std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void	printFloat(const std::string &literal)
{
	float	value;
	 
	if (!isNumber(literal))
	{
		std::cout << "float: nanf" << std::endl;
		return ;
	}
	value = static_cast<float>(atof(literal.c_str()));
	if (value == std::numeric_limits<float>::infinity())
	{
		std::cout << "float: +inff" << std::endl;
		return;
	}
	if (value == -std::numeric_limits<float>::infinity())
	{
		std::cout << "float: -inff" << std::endl;
		return;
	}
	std::cout << "float: " << value;
	std::stringstream ss;
	ss << value;
	if (ss.str().find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void	printDouble(const std::string &literal)
{
	double	value;
	 
	if (!isNumber(literal))
	{
		std::cout << "double: nan" << std::endl;
		return ;
	}
	value = static_cast<double>(atof(literal.c_str()));
	if (value == std::numeric_limits<double>::infinity())
	{
		std::cout << "double: +inf" << std::endl;
		return;
	}
	if (value == -std::numeric_limits<double>::infinity())
	{
		std::cout << "double: -inf" << std::endl;
		return;
	}
	std::cout << "double: " << value;
	std::stringstream ss;
	ss << value;
	if (ss.str().find('.') == std::string::npos)
		std::cout << ".0";
	std::cout << std::endl;
}

void	ScalarConverter::convert(const std::string &literal)
{
	printChar(literal);
	printInt(literal);
	printFloat(literal);
	printDouble(literal);
}
