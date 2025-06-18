#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain	*_brain;
	
	public:
		Cat(void);
		Cat(const std::string &type);
		Cat(const Cat &other);
		Cat &operator=(const Cat &other);
		virtual ~Cat();

		void	makeSound(void) const;
		void	thinkAbout(std::string idea, unsigned int idx);
		void	showThoughts(void) const;
};