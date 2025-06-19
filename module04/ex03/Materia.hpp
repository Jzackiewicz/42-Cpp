#pragma once

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Materia: public AMateria
{
	protected:
		std::string	_type;
	
	public:
		Materia(std::string const &type);
		Materia(const Materia& other);
		Materia &operator=(const Materia &other);
		virtual ~Materia();

		std::string const &getType(void) const;
		virtual Materia *clone() const;
		virtual void use(ICharacter &target);
};