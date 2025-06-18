#include "Cat.hpp"

Cat::Cat(void): Animal("Kitty")
{
	this->_type = "Kitty";
	std::cout << "Cat " << this->_type << " created." << std::endl;;
}

Cat::Cat(const std::string &type): Animal(type)
{
	this->_type = type;
	std::cout << "Cat " << this->_type << " created." << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	std::cout << "Cat " << this->_type << " copied." << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "Cat " << this->_type << " assigned." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	std::cout << "Cat " << this->_type << " destroyed." << std::endl;;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << this->_type << " meowed." << std::endl;
}
