#pragma once

#include <iostream>
#include "Materia.hpp"

class Ice : public Materia
{
	public:
		Ice(void);
		Ice(const Ice& other);
		Ice &operator=(const Ice &other);
		virtual ~Ice(void);
		virtual Ice *clone(void) const;
		virtual void use(ICharacter &target);
};