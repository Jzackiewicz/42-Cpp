#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat	bureaucrat("John Pork", 11);
	Intern		intern;
	AForm		*form;
	
	std::cout << bureaucrat;

	for (int i = 0; i < 3; ++i)
	{
		if (i == 0)
			form = intern.makeForm("shrubbery creation", "krzak");
		else if (i == 1)
			form = intern.makeForm("robotomy request", "rob");
		else if (i == 2)
			form = intern.makeForm("presidential pardon", "sori");
		if (form)
		{
			bureaucrat.beSigned(*form);
			std::cout << *form;
			bureaucrat.executeForm(*form);
			delete (form);
		}
		else
			std::cerr << "\033[31m" << "Failed to create ShrubberyCreationForm.\033[0m" << std::endl;
	}
	return (1);
}
