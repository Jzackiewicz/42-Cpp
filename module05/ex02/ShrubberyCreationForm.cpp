#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		const_cast<std::string&>(this->_target) = other._target;
	}
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	try
	{
		if (!this->getIsSigned())
			throw AForm::FormNotSignedException();
		if (executor.getGrade() > this->getExecGrade())
			throw AForm::GradeTooLowException();
	}
	catch (const AForm::FormNotSignedException &e)
	{
		std::cerr << "\033[31m" << "Caught FormNotSignedException \033[0m[" << this->getName() << "]: \n" << e.what() << std::endl;
		return;
	}
	catch (const AForm::GradeTooLowException &e)
	{
		std::cerr << "\033[31m" << "Caught GradeTooLowException \033[0m[" << this->getName() << "]: \n" << e.what() << std::endl;
		return;
	}

	std::ofstream ofs((this->_target + "_shrubbery").c_str());
	if (!ofs)
	{
		std::cerr << "Error opening file: " << this->_target << "_shrubbery" << std::endl;
		return;
	}

	ofs << "         _-_-_\n";
	ofs << "      /~~   ~~\\\n";
	ofs << "   /~~         ~~\\\n";
	ofs << "  {               }\n";
	ofs << "   \\  _-_-_-_-_  /\n";
	ofs << "     ~~~~~~~~~~~\n";
	ofs << "         _-_-_\n";
	ofs << "      /~~   ~~\\\n";
	ofs << "   /~~         ~~\\\n";
	ofs << "  {               }\n";
	ofs << "   \\  _-_-_-_-_  /\n";
	ofs << "     ~~~~~~~~~~~\n";
	ofs << "         _-_-_\n";
	ofs << "      /~~   ~~\\\n";
	ofs << "   /~~         ~~\\\n";
	ofs << "  {               }\n";
	ofs << "   \\  _-_-_-_-_  /\n";
	ofs << "     ~~~~~~~~~~~\n";

	ofs.close();
}