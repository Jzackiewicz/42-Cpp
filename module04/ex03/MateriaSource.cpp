#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		this->_inventory[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const &other)
{
	for (int i = 0; i < 4; i++)
	{
		delete (this->_inventory[i]);
		if (other._inventory[i] != NULL)
			this->_inventory[i] = other._inventory[i];
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(MateriaSource const &other)
{
	if (this != &other)
	{
		for (int i = 0; i < 4; i++)
		{
			delete (this->_inventory[i]);
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i];
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		delete (this->_inventory[i]);
	}
};

void	MateriaSource::learnMateria(AMateria* mat)
{
	for (int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = mat;
			return ;
		}
	}
	std::cout << "Can't learn more Materias!" << std::endl;
	delete mat;
}

AMateria	*MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventory[i] && this->_inventory[i]->getType() == type)
		{
			return (this->_inventory[i]->clone());
		}
	}
	std::cout << "Materia of type " << type << " not found!" << std::endl;
	return (NULL);
}
