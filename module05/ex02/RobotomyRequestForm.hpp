#pragma once

#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;
	
		public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
		~RobotomyRequestForm(void);

		const std::string &getTarget(void) const;
		void execute(const Bureaucrat &executor) const;

		class RobotomyFailedException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};