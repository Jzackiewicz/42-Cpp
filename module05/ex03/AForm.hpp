#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

class AForm
{
	protected:
		const std::string	_name;
		bool				_isSigned;
		const int			_signGrade;
		const int			_execGrade;
	
	public:
		AForm(const std::string &name, int signGrade, int execGrade);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm(void);

		const std::string	&getName(void) const;
		bool				getIsSigned(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		void				beSigned(Bureaucrat &bureaucrat);
		virtual void		execute(const Bureaucrat &executor) const = 0;

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

	class FormNotSignedException: public std::exception
	{
		public:
			const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &Aform);
