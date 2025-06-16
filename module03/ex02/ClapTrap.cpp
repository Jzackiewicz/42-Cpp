#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string name)
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->_name << " created." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name), _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap " << this->_name << " copied." << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "ClapTrap " << this->_name << " assigned." << std::endl;
	}
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (!this->checkHitPoints() || !this->checkEnergyPoints())
		return ;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->checkHitPoints())
		return ;
	if (amount > this->_hitPoints)
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount
			  << " points of damage and now has " << this->_hitPoints << " hit points!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->checkHitPoints() || !this->checkEnergyPoints())
		return ;
	this->_hitPoints += amount;
	this->_energyPoints--;
	std::cout << "ClapTrap " << this->_name << " repairs " << amount <<
				 " hit points back and now has " << this->_hitPoints << " hit points!" << std::endl;
}

bool	ClapTrap::checkEnergyPoints(void)
{
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no energy points left!" << std::endl;
		return (false);
	}
	return (true);
}

bool	ClapTrap::checkHitPoints(void)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " has no hit points left!" << std::endl;
		return (false);
	}
	return (true);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}
unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}
unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}
