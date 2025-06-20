#pragma once

#include "ICharacter.hpp"
#include "Materia.hpp"

class Character: public ICharacter
{
	protected:
		std::string	_name;
		AMateria	*_inventory[4];
		AMateria	*_floor[100];
	
	public:
		Character(std::string const &name);
		Character(const Character& other);
		Character &operator=(const Character &other);
		virtual ~Character();

		std::string const	&getName(void) const;
		void				equip(AMateria* m);
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

};

