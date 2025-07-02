#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat				bureaucrat("John Pork", 2);
	ShrubberyCreationForm	shrubberyForm("krzak");
	PresidentialPardonForm	pardonForm("sori");
	RobotomyRequestForm		robotomyForm("rob");
 
	std::cout << bureaucrat;
	std::cout << shrubberyForm;
	std::cout << pardonForm;
	std::cout << robotomyForm;

	shrubberyForm.beSigned(bureaucrat);
	pardonForm.beSigned(bureaucrat);
	robotomyForm.beSigned(bureaucrat);

	shrubberyForm.execute(bureaucrat);
	pardonForm.execute(bureaucrat);
	robotomyForm.execute(bureaucrat);
	return (1);
}