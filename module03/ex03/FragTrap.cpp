#include "FragTrap.hpp"

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap " << this->_name << " created." << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
	std::cout << "FragTrap " << this->_name << " copied." << std::endl;
}
FragTrap &FragTrap::operator=(const FragTrap &other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
		std::cout << "FragTrap " << this->_name << " assigned." << std::endl;
	}
	return *this;
}
FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	if (!this->checkHitPoints())
		return;
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}

void	FragTrap::attack(const std::string &target)
{
	if (!checkHitPoints() || !checkEnergyPoints())
		return;
	
	this->_energyPoints--;
	std::cout << "FragTrap " << this->_name << " attacks " << target 
			  << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}
