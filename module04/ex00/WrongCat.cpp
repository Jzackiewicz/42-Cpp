#include "WrongCat.hpp"

WrongCat::WrongCat(void): WrongAnimal()
{
	this->_type = "Kitty";
	std::cout << "WrongCat " << this->_type << " created." << std::endl;;
}

WrongCat::WrongCat(const std::string &type): WrongAnimal(type)
{
	this->_type = type;
	std::cout << "WrongCat " << this->_type << " created." << std::endl;
}

WrongCat::WrongCat(const WrongCat& other)
{
	this->_type = other._type;
	std::cout << "WrongCat " << this->_type << " copied." << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	std::cout << "WrongCat " << this->_type << " assigned." << std::endl;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat " << this->_type << " destroyed." << std::endl;;
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat " << this->_type << " meowed." << std::endl;
}
