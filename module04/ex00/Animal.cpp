#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Bob";
	std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(const std::string &type)
{
	std::cout << "Animal " << this->_type << " created." << std::endl;
	this->_type = type;
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal " << this->_type << " copied." << std::endl;
	this->_type = other._type;
	*this = other;
}

Animal	&Animal::operator=(const Animal &other)
{
	std::cout << "Animal " << this->_type << " assigned." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal " << this->_type << " destroyed." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Animal " << this->_type << " made a sound" << std::endl;
}
