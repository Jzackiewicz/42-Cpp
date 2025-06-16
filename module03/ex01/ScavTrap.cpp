#include "ScavTrap.hpp"
#include <iostream>
#include <string>

ScavTrap::ScavTrap(const std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap " << this->_name << " created." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "ScavTrap " << this->_name << " copied." << std::endl;
}
ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "ScavTrap " << this->_name << " assigned." << std::endl;
	}
	return *this;
}
ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed." << std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " is now in Gate Keeper mode." << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (!checkHitPoints() || !checkEnergyPoints())
		return;
	
	this->_energyPoints--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target 
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}