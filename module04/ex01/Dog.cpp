#include "Dog.hpp"

Dog::Dog(void): Animal("Dawg")
{
	this->_type = "Dawg";
	std::cout << "Dog " << this->_type << " created." << std::endl;;
}

Dog::Dog(const std::string &type): Animal(type)
{
	this->_type = type;
	std::cout << "Dog " << this->_type << " created." << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "Dog " << this->_type << " copied." << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Dog " << this->_type << " assigned." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog " << this->_type << " destroyed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << this->_type << " barked." << std::endl;
}
