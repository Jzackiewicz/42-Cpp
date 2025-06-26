#pragma once

#include <iostream>
#include <string>
#include <iosfwd>

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

		std::string	getName(void);
		int			getGrade(void);
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureaucrat);