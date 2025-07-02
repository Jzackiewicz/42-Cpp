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
	if (!this->getIsSigned())
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->getExecGrade())
		throw AForm::GradeTooLowException();

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
	std::cout << "\033[32m" << "Shrubbery created successfully in " << this->_target << "_shrubbery file." << "\033[0m" << std::endl;
}

