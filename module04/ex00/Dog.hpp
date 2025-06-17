#pragma once

#include "Animal.hpp"

class Dog: public Animal
{
	private:
	;
	
	public:
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog& obj);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		void makeSound(void) const;

};