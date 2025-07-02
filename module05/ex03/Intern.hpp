#pragma once

#include "AForm.hpp"
#include <iostream>

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &other);
		Intern &operator=(const Intern &other);
		~Intern(void);

		AForm *makeForm(const std::string &formName, const std::string &target) const;

		class FormNotFoundException : public std::exception
		{
			public:
				const char *what() const throw();
		};
};