#include "AMateria.hpp"

AMateria::AMateria(std::string const &type)
{
	this->_type = type;
}

AMateria::AMateria(const AMateria& obj)
{
	this->_type = obj._type;
}

AMateria	&AMateria::operator=(const AMateria& obj)
{
	if (this != &obj)
	{
		this->_type = obj._type;
	}
	return (*this);
}

AMateria::~AMateria(void)
{
	;
}

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter &target)
{
	std::cout << "* uses AMateria of " << this->_type << " type at " << target.getName() << std::endl;
}
