#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main(void)
{
	IMateriaSource	*src = new MateriaSource();
	ICharacter		*me = new Character("me");
	ICharacter		*bob = new Character("bob");
	ICharacter		*me_copy;
	AMateria		*tmp;

	me_copy = me;
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	tmp = src->createMateria("ice");
	me_copy->equip(tmp);
	tmp = src->createMateria("cure");
	me_copy->equip(tmp);
	tmp = src->createMateria("ice");
	me_copy->equip(tmp);
	tmp = src->createMateria("cure");
	me_copy->equip(tmp);
	tmp = src->createMateria("cure");
	me_copy->equip(tmp);
	
	me_copy->use(0, *bob);
	me_copy->use(1, *bob);
	me_copy->use(2, *bob);
	me_copy->use(3, *bob);
	me_copy->use(4, *bob);
	
	delete (bob);
	delete (me_copy);
	delete (src);
	
	return (0);
}