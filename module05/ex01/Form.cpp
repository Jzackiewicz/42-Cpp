#include "Form.hpp"

Form::Form(const std::string &name, int sign_grade, int exec_grade): _name(name), _is_signed(false), _sign_grade(sign_grade), _exec_grade(exec_grade) {}

Form::Form(const Form& obj): _name(obj._name), _is_signed(obj._is_signed), _sign_grade(obj._sign_grade), _exec_grade(obj._exec_grade)
{
	;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_is_signed = other._is_signed;
	}
	return *this;
}

Form::~Form(void) {}


void	Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _sign_grade)
		throw (Form::GradeTooLowException());
	_is_signed = true;
}