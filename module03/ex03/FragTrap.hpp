#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static unsigned int const _initHitPoints = 100;
		static unsigned int const _initEnergyPoints = 100;
		static unsigned int const _initAttackDamage = 30;

	public:
		FragTrap(void);
		FragTrap(const std::string name);
		FragTrap(const FragTrap &other);
		FragTrap &operator=(const FragTrap &other);
		~FragTrap();

		void	attack(const std::string &target);
		void	highFivesGuys(void);
};
