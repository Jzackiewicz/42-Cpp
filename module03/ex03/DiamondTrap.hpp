#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap  
{
	private:
		std::string	_name;
	
	public:
		DiamondTrap(const std::string name);
		DiamondTrap(const DiamondTrap& obj);
		DiamondTrap &operator=(const DiamondTrap &other);
		~DiamondTrap();

		void	attack(const std::string &target);
		void	whoAmI(void);

};