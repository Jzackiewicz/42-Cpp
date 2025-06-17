#include "Dog.hpp"

Dog::Dog(void)
{
	this->_type = "Dawg";
	std::cout << "Dog " << this->_type << " created." << std::endl;;
}

Dog::Dog(const std::string &type)
{
	std::cout << "Dog " << this->_type << " created." << std::endl;
	this->_type = type;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	std::cout << "Dog " << this->_type << " copied." << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	std::cout << "Dog " << this->_type << " assigned." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
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
