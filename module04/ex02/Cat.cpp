#include "Cat.hpp"

Cat::Cat(void): Animal()
{
	this->_type = "Kitty";
	this->_brain = new Brain();
	
	for (unsigned int i = 0; i < 10; i++)
		this->_brain->setIdea("fimsh", i);
	std::cout << "Cat " << this->_type << " created." << std::endl;;
}

Cat::Cat(const std::string &type): Animal(type)
{
	this->_type = type;
	this->_brain = new Brain();
	for (unsigned int i = 0; i < 10; i++)
		this->_brain->setIdea("fimsh", i);
	std::cout << "Cat " << this->_type << " created." << std::endl;
}

Cat::Cat(const Cat& other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Cat " << this->_type << " copied." << std::endl;
}

Cat	&Cat::operator=(const Cat& other)
{
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain(*other._brain);
	}
	std::cout << "Cat " << this->_type << " assigned." << std::endl;
	return (*this);
}

Cat::~Cat(void)
{
	delete (this->_brain);
	std::cout << "Cat " << this->_type << " destroyed." << std::endl;;
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << this->_type << " meowed." << std::endl;
}

void	Cat::thinkAbout(std::string idea, unsigned int idx)
{
	if (idx > 99)
		return ;
	this->_brain->setIdea(idea, idx);
}

void	Cat::showThoughts(void) const
{
	for (unsigned int j = 0; j < 20; j++)
			std::cout << this->_brain->getIdea(j) << " |";
	std::cout << std::endl;
}