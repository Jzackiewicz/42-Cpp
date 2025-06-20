#pragma once

#include <iostream>
#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria	*_inventory[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		virtual ~MateriaSource();
		
		virtual void learnMateria(AMateria* mat);
		virtual AMateria* createMateria(std::string const & type);
};