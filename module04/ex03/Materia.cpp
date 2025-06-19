#include "Materia.hpp"

Materia::Materia(std::string const &type): AMateria(type), _type(type){}

Materia::Materia(const Materia& other): AMateria(other)
{
	this->_type = other._type;
}

Materia &Materia::operator=(const Materia& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		AMateria::operator=(other);
	}
	return (*this);
}

Materia::~Materia(void) {}

Materia *Materia::clone(void) const
{
	return (new Materia(*this));
}

void Materia::use(ICharacter &target)
{
	std::cout << "* uses Materia of " << this->_type << " type at " << target.getName() << std::endl;
}