#pragma once

#include <iostream>
#include <string>
#include <stdexcept>
#include <cstdlib>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	
	public:
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		Bureaucrat &operator=(const Bureaucrat &other);

		void		incrementGrade(void);
		void		decrementGrade(void);
		
		std::string	getName(void) const;
		int			getGrade(void) const;
		void		setGrade(int grade);
		void		beSigned(AForm &AForm);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();
		};

};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat);