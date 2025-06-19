#pragma once

#include <iostream>
#include "Materia.hpp"

class Cure : public Materia
{
	public:
		Cure(void);
		Cure(const Cure& other);
		Cure &operator=(const Cure &other);
		virtual ~Cure(void);
		virtual Cure *clone(void) const;
		virtual void use(ICharacter &target);
};