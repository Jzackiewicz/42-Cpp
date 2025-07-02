#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern(void) {}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}

Intern::~Intern(void) {}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) const
{
	try
	{
		if (formName == "shrubbery creation")
			return (new ShrubberyCreationForm(target));
		else if (formName == "robotomy request")
			return (new RobotomyRequestForm(target));
		else if (formName == "presidential pardon")
			return (new PresidentialPardonForm(target));
		else
			throw FormNotFoundException();
	}
	catch (const FormNotFoundException &e)
	{
		std::cerr << "\033[31m" << "Caught FormNotFoundException \033[0m: \n" << e.what() << std::endl;
		return (NULL);
	}
}

const char	*Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found.");
}
