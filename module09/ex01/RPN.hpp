#pragma once

#include <string>
#include <iostream>
#include <exception>
#include <stack>

class RPN
{
	private:
		std::string	_expression;

		static int	_calculate(int a, int b, char op);
		void		_loadExpression(const std::string &expression);

	public:
		RPN(const std::string &expression);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN(void);

		int	evaluate() const;
};