#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Dog(void);
		Dog(const std::string &type);
		Dog(const Dog& obj);
		Dog &operator=(const Dog &other);
		virtual ~Dog();

		void	makeSound(void) const;
		void	thinkAbout(std::string idea, unsigned int idx);
		void	showThoughts(void) const;

};