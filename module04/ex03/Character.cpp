#include "ICharacter.hpp"
#include "Character.hpp"

Character::Character(std::string const &name): _name(name)
{
	for (unsigned int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
	for (unsigned int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
}

Character::Character(Character const &other)
{
	this->_name = other._name;
	for (unsigned int i = 0; i < 4; i++)
	{
		delete(this->_inventory[i]);
		if (other._inventory[i])
			this->_inventory[i] = other._inventory[i]->clone();
		else
			this->_inventory[i] = NULL;
	}
	for (unsigned int i = 0; i < 100; i++)
	{
		delete (this->_floor[i]);
		if (other._floor[i])
			this->_floor[i] = other._floor[i]->clone();
		else
			this->_floor[i] = NULL;
	}
}

Character	&Character::operator=(Character const &other)
{
	if (this != &other)
	{
		this->_name = other.getName();
		for (unsigned int i = 0; i < 4; i++)
		{
			delete (_inventory[i]);
			if (other._inventory[i])
				this->_inventory[i] = other._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
		for (unsigned int i = 0; i < 100; i++)
		{
			delete (this->_floor[i]);
			if (other._floor[i])
				this->_floor[i] = other._floor[i]->clone();
			else
				this->_floor[i] = NULL;
		}
	}
	return (*this);
}

Character::~Character(void)
{
	for (unsigned int i = 0; i < 4; i++)
		delete (_inventory[i]);
	for (unsigned int i = 0; i < 100; i++)
		delete (this->_floor[i]);
}

std::string const &Character::getName(void) const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	for (unsigned int i = 0; i < 4; i++)
	{
		if (!this->_inventory[i])
		{
			this->_inventory[i] = m;
			return ;
		}
	}
	delete (m);
	std::cout << "Inventory is full!" << std::endl;
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index out of bounds!" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
    {
        std::cout << "Inventory slot is already empty!" << std::endl;
        return;
    }
	for (int i = 0; i < 100; i++)
	{
		if (!this->_floor[i])
		{
			this->_floor[i] = this->_inventory[idx];
			this->_inventory[idx] = NULL;
			return ;
		}
	}
	std::cout << "Can't unequip! The floor is full!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3)
	{
		std::cout << "Index out of bounds!" << std::endl;
		return ;
	}
	if (!this->_inventory[idx])
	{
		std::cout << "This slot ("<< idx <<") is empty!" << std::endl;
		return ;
	}
	this->_inventory[idx]->use(target);
}
