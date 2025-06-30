#pragma once

#include "AForm.hpp"
#include <fstream>
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm(void);

		void execute(const Bureaucrat &executor) const;
};