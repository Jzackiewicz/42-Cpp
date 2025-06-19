#include "ICharacter.hpp"
#include "Cure.hpp"

Cure::Cure(void) : Materia("cure") {}

Cure::Cure(const Cure& other) : Materia(other) {}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		Materia::operator=(other);
	}
	return (*this);
}

Cure::~Cure(void) {}

Cure *Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
