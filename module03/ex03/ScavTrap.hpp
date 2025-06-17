#pragma once
#include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap
{
	protected:
		static unsigned int const _initHitPoints = 100;
		static unsigned int const _initEnergyPoints = 50;
		static unsigned int const _initAttackDamage = 20;

	public:
		ScavTrap(void);
		ScavTrap(const std::string name);
		ScavTrap(const ScavTrap &other);
		ScavTrap &operator=(const ScavTrap &other);
		~ScavTrap();

		void	attack(const std::string &target);
		void	guardGate(void);
};
