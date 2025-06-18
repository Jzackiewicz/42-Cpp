#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "hmm";
	}
	std::cout << "Brain created." << std::endl;
}

Brain::Brain(const Brain &obj)
{
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = obj.ideas[i];
	}
	std::cout << "Brain copied." << std::endl;
}

Brain &Brain::operator=(const Brain &obj)
{
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
		{
			this->ideas[i] = obj.ideas[i];
		}
		std::cout << "Brain assigned." << std::endl;
	}
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destroyed." <<std::endl;
}

void	Brain::setIdea(std::string idea, unsigned int idx)
{
	if (idx > 99)
	{
		std::cout << "Index out of bounds." << std::endl;
		return ;
	}
	this->ideas[idx] = idea;
}

std::string	Brain::getIdea(unsigned int idx)
{
	if (idx > 99)
	{
		std::cout << "Index out of bounds." << std::endl;
		return (NULL);
	}
	return (this->ideas[idx]);
}
