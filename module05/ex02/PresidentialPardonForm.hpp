#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		~PresidentialPardonForm(void);

		void execute(const Bureaucrat &executor) const;
};
