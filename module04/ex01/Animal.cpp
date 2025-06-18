#include "Animal.hpp"

Animal::Animal(void)
{
	this->_type = "Bob";
	std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(const std::string &type)
{
	this->_type = type;
	std::cout << "Animal " << this->_type << " created." << std::endl;
}

Animal::Animal(const Animal &other)
{
	this->_type = other._type;
	*this = other;
	std::cout << "Animal " << this->_type << " copied." << std::endl;
}

Animal	&Animal::operator=(const Animal &other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Animal " << this->_type << " assigned." << std::endl;
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

void	Animal::thinkAbout(std::string idea, unsigned int idx)
{
	(void)idea;
	(void)idx;
}

void	Animal::showThoughts(void) const
{
	;
}
