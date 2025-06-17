#include "Cat.hpp"

Cat::Cat(void)
{
	this->_type = "Kitty";
	std::cout << "Cat " << this->_type << " created." << std::endl;;
}

Cat::Cat(const std::string &type)
{
	std::cout << "Cat " << this->_type << " created." << std::endl;
	this->_type = type;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	std::cout << "Cat " << this->_type << " copied." << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	std::cout << "Cat " << this->_type << " assigned." << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
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
