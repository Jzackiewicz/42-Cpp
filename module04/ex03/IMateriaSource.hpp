#pragma once

#include <iostream>
class AMateria;

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria* mat) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};
