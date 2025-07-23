#include "RPN.hpp"
#include <sstream>

RPN::RPN(const std::string &expression)
{
	this->_loadExpression(expression);
	if (expression.empty())
		throw std::invalid_argument("Error: Expression cannot be empty!");
}

RPN::RPN(const RPN &other) : _expression(other._expression) {}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		this->_expression = other._expression;
	return (*this);
}

RPN::~RPN(void) {}

void	RPN::_loadExpression(const std::string &expression)
{
	std::stringstream ss(expression);
	std::string validTokens = "+-/*";
	std::string	curToken;

	while (ss >> curToken)

	for (size_t i = 0; i < expression.size(); i++)
	{
		if (curToken.length() != 1 || (!std::isdigit(curToken[0]) &&
			validTokens.find(curToken[0]) == std::string::npos))
			throw std::invalid_argument("Error: Invalid token in expression");
	}
	this->_expression = expression;
}

int		RPN::_calculate(int a, int b, char op)
{
	switch (op)
	{
	case '+':
		return (a + b);
	case '-':
		return (a - b);
	case '*':
		return (a * b);
	case '/':
		if (b == 0)
			throw std::runtime_error("Error: Cannot divide by zero!");
		else
			return (a / b);
	default:
		throw std::invalid_argument("Error: Invalid operator!");
	}
}

int	RPN::evaluate(void) const
{
	std::stringstream	ss(this->_expression);
	std::string			curToken;
	std::stack<int>		rpnNums;
	int					a, b, result;

	while (ss >> curToken)
	{
		if (isdigit(curToken[0]))
			rpnNums.push(curToken[0] - '0');
		else
		{
			if (rpnNums.size() < 2)
				throw std::runtime_error("Error: Invalid expression!");
			b = rpnNums.top();
			rpnNums.pop();
			a = rpnNums.top();
			rpnNums.pop();
			result = RPN::_calculate(a, b, curToken[0]);
			rpnNums.push(result);
		}
	}
	if (rpnNums.size() != 1)
		throw std::runtime_error("Error: Invalid expression!");
	return (rpnNums.top());
}
