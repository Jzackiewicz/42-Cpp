#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
	: AForm(other), _target(other._target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		const_cast<std::string&>(this->_target) = other._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	srand(std::time(0));
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw GradeTooLowException();
	if (rand() % 2)
		std::cout << "\033[32m" << "Bzzzzzz... " << this->_target << " has been robotomized successfully 50% of the time!" << "\033[0m" << std::endl;
	else
		throw RobotomyFailedException();
}

const char *RobotomyRequestForm::RobotomyFailedException::what() const throw()
{
	return ("Robotomy failed.");
}

