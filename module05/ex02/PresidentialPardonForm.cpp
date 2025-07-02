#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
	: AForm(other), _target(other._target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{		AForm::operator=(other);
		const_cast<std::string&>(this->_target) = other._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

void PresidentialPardonForm::execute(const Bureaucrat &bureaucrat) const
{
	try
	{
		if (!this->getIsSigned())
			throw FormNotSignedException();
		if (bureaucrat.getGrade() > this->getExecGrade())
			throw GradeTooLowException();
		std::cout << "\033[32m" << this->_target << " has been pardoned by Zaphod Beeblebrox.\033[0m" << std::endl;
	}
	catch (const FormNotSignedException &e)
	{
		std::cerr << "\033[31m" << "Caught FormNotSignedException \033[0m[" << this->getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->getName() << "]: \n" << e.what() << std::endl;
		return;
	}
}
