#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	try
	{
		this->setGrade(grade);
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		this->_grade = 150;
		return;
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		this->_grade = 150;
		return;
	}
	this->_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name)
{
	this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return (*this);
}

std::string	Bureaucrat::getName(void) const
{
	return (this->_name);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	try
	{
		this->setGrade(this->_grade - 1);
	}
	catch (const GradeTooHighException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
}

void	Bureaucrat::decrementGrade(void)
{
	try
	{
		this->setGrade(this->_grade + 1);
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	this->_grade = grade;
}

void	Bureaucrat::beSigned(AForm &AForm)
{
	try
	{
		AForm.beSigned(*this);
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		std::cerr << "\033[35m" << this->_name << " couldnt's sign " << AForm.getName() << " because their grade is too low." << "\033[0m" << std::endl;
		return;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high.");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low.");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return (os);
}

void Bureaucrat::executeForm(const AForm &AForm) const
{
	try
	{
		AForm.execute(*this);
		std::cout << "\033[32m" << this->_name << " executed " << AForm.getName() << "\033[0m" << std::endl;
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[31m" << "Caught FormNotSignedException \033[0m[" << AForm.getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << AForm.getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const AForm::GradeTooHighException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m[" << AForm.getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const RobotomyRequestForm::RobotomyFailedException &e)
	{
		std::cerr << "\033[31m" << "Caught RobotomyFailedException \033[0m[" << AForm.getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const std::exception &e)
	{
		std::cerr << "\033[31m" << "Caught exception \033[0m[" << AForm.getName() << "]: \n" << e.what() << std::endl;
		return;
	}
}

