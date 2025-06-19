#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string	_type;
	
	public:
		AMateria(std::string const &type);
		AMateria(const AMateria& obj);
		AMateria &operator=(const AMateria &other);
		virtual ~AMateria();

		std::string const &getType(void) const;
		virtual AMateria *clone() const = 0;
		virtual void use(ICharacter &target);
};