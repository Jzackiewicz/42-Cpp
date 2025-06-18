#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	_type;
	
	public:
		WrongAnimal(void);
		WrongAnimal(const std::string &type);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal(void);

		std::string	getType(void) const;
		void		makeSound(void) const;
};