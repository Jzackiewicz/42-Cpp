#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string name)
			: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	this->_name = name;
	this->_hitPoints = ScavTrap::_initHitPoints;
	this->_energyPoints = ScavTrap::_initEnergyPoints;
	this->_attackDamage = FragTrap::_initAttackDamage;
	std::cout << "DiamondTrap " << this->_name << " created." << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), FragTrap(other), ScavTrap(other)
{
	this->_name = other._name;
	ClapTrap::_name = other._name + "_clap_name";
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "DiamondTrap " << this->_name << " copied." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "DiamondTrap " << this->_name << " assigned." << std::endl;
	}
	return *this;
}
DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed." << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << this->_name << " and my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}