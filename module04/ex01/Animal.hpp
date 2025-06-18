#pragma once

#include <iostream>

class Animal
{
	protected:
		std::string	_type;
	
	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal(void);

		virtual std::string	getType(void) const;
		virtual void		makeSound(void) const;
		virtual void		thinkAbout(std::string idea, unsigned int idx);
		virtual void		showThoughts(void) const;
};