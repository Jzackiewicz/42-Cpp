#pragma once

#include "Animal.hpp"

class Cat: public Animal
{
	private:
	;
	
	public:
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		void makeSound(void) const;
};