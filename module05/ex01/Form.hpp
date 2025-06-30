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
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		Form(const std::string &name, int signGrade, int execGrade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				beSigned(Bureaucrat &bureaucrat);

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
