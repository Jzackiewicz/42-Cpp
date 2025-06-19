#include "ICharacter.hpp"
#include "Ice.hpp"

Ice::Ice(void) : Materia("ice") {}

Ice::Ice(const Ice& other) : Materia(other) {}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->_type = other._type;
		Materia::operator=(other);
	}
	return (*this);
}

Ice::~Ice(void) {}

Ice *Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}