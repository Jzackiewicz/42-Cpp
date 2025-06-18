#include "Dog.hpp"

Dog::Dog(void): Animal("Dawg")
{
	this->_type = "Dawg";
	this->_brain = new Brain();
	for (unsigned int i = 0; i < 10; i++)
		this->_brain->setIdea("chimken", i);
	std::cout << "Dog " << this->_type << " created." << std::endl;;
}

Dog::Dog(const std::string &type): Animal(type)
{
	this->_type = type;
	this->_brain = new Brain();
	for (unsigned int i = 0; i < 10; i++)
		this->_brain->setIdea("chimken", i);
	std::cout << "Dog " << this->_type << " created." << std::endl;
}

Dog::Dog(const Dog& other)
{
	this->_type = other._type;
	this->_brain = new Brain(*other._brain);
	std::cout << "Dog " << this->_type << " copied." << std::endl;
}

Dog	&Dog::operator=(const Dog& other)
{
	if (this != &other)
	{
		if (this->_brain)
			delete (this->_brain);
		this->_brain = new Brain(*other._brain);
		this->_type = other._type;
	}
	std::cout << "Dog " << this->_type << " assigned." << std::endl;
	return (*this);
}

Dog::~Dog(void)
{
	delete (this->_brain);
	std::cout << "Dog " << this->_type << " destroyed." << std::endl;
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << this->_type << " barked." << std::endl;
}

void	Dog::thinkAbout(std::string idea, unsigned int idx)
{
	if (idx > 99)
		return ;
	this->_brain->setIdea(idea, idx);
}

void	Dog::showThoughts(void) const
{
	for (unsigned int j = 0; j < 20; j++)
			std::cout << this->_brain->getIdea(j) << " |";
	std::cout << std::endl;
}