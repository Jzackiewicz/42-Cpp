#include "Form.hpp"

Form::Form(const std::string &name, int signGrade, int execGrade): _name(name), _isSigned(false), _signGrade(signGrade), _execGrade(execGrade)
{
	try
	{
		if (signGrade < 1 || execGrade < 1)
			throw (Form::GradeTooHighException());
		if (signGrade > 150 || execGrade > 150)
			throw (Form::GradeTooLowException());
	}
	catch(const Form::GradeTooHighException& e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->_name <<"]: \n" << e.what() << std::endl;
		return;
	}
}

Form::Form(const Form& obj): _name(obj._name), _isSigned(obj._isSigned), _signGrade(obj._signGrade), _execGrade(obj._execGrade) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form(void) {}

const std::string &Form::getName(void) const
{
	return (this->_name);
}

bool Form::getIsSigned(void) const
{
	return (this->_isSigned);
}

int Form::getSignGrade(void) const
{
	return (this->_signGrade);
}

int Form::getExecGrade(void) const
{
	return (this->_execGrade);
}

void	Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw (Form::GradeTooLowException());
	this->_isSigned = true;
		std::cout << "\033[32m" << bureaucrat.getName() << " signed " << this->getName() << "\033[0m" << std::endl;
}


const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high.");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low.");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No")
	   << ", Sign Grade: " << form.getSignGrade()
	   << ", Exec Grade: " << form.getExecGrade() << std::endl;
	return os;
}