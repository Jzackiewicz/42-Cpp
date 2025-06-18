#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->_type = "Bob";
	std::cout << "WrongAnimal " << this->_type << " created." << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
	this->_type = type;
	std::cout << "WrongAnimal " << this->_type << " created." << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	this->_type = other._type;
	*this = other;
	std::cout << "WrongAnimal " << this->_type << " copied." << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "WrongAnimal " << this->_type << " assigned." << std::endl;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << this->_type << " destroyed." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal " << this->_type << " made a sound" << std::endl;
}
