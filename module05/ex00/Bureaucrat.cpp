#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
}

Bureaucrat::~Bureaucrat(void)
{
	;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName(void)
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void)
{
	return (this->_grade);
}


