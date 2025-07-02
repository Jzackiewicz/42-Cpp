#include "AForm.hpp"

AForm::AForm(const std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	try
	{
		if (signGrade < 1 || execGrade < 1)
			throw (AForm::GradeTooHighException());
		if (signGrade > 150 || execGrade > 150)
			throw (AForm::GradeTooLowException());
	}
	catch(const AForm::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
}

AForm::AForm(const AForm& obj): _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

AForm::~AForm(void) {}

const std::string &AForm::getName(void) const
{
	return (this->_name);
}

bool AForm::getIsSigned(void) const
{
	return (this->_isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->_signGrade);
}

int AForm::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (AForm::GradeTooLowException());
	this->_isSigned = true;
		std::cout << "\033[32m" << bureaucrat.getName() << " signed " << this->getName() << "\033[0m" << std::endl;
}


const char *AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high.");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low.");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("AForm is not signed.");
}

std::ostream &operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm: " << Aform.getName() << ", Signed: " << (Aform.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << Aform.getSignGrade()
	   << ", Exec Grade: " << Aform.getExecGrade() << std::endl;
	return (os);
}