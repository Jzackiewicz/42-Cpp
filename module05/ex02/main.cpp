#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John Doe", 1);
	RobotomyRequestForm form("Home");
	
	std::cout << bureaucrat;
	std::cout << form;

	bureaucrat.beSigned(form);
	std::cout << "Incrementing bureaucrat's grade..." << std::endl;
	std::cout << bureaucrat << std::endl;
	bureaucrat.beSigned(form);
	form.execute(bureaucrat);
	std::cout << form << std::endl;
	return (1);
}