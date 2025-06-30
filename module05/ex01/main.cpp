#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John Doe", 50);
	Form form("Form A", 45, 30);
	
	try
	{
		Form formB("Form B", 151, 1);
	}
	catch (const Form::GradeTooHighException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooHighException \033[0m: " << e.what() << std::endl;
	}
	catch (const Form::GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m: " << e.what() << std::endl;
	}

	std::cout << bureaucrat;
	std::cout << form;

	bureaucrat.beSigned(form);
	std::cout << "Incrementing bureaucrat's grade..." << std::endl;
	bureaucrat.incrementGrade();
	bureaucrat.incrementGrade();
	bureaucrat.incrementGrade();
	bureaucrat.incrementGrade();
	bureaucrat.incrementGrade();
	std::cout << bureaucrat << std::endl;
	bureaucrat.beSigned(form);
	std::cout << form << std::endl;
	return (1);
}