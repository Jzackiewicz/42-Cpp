#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

class Form
{
	private:
		const std::string	_name;
		bool				_is_signed;
		const int			_sign_grade;
		const int			_exec_grade;
	
	public:
		Form(const std::string &name, int sign_grade, int exec_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		void	beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException: public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const Form &form);
