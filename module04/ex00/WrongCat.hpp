#pragma once

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	private:
		;
	
	public:
		WrongCat(void);
		WrongCat(const std::string &type);
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		virtual ~WrongCat();

		void makeSound(void) const;
};