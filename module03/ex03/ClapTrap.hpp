#pragma once

#include <iostream>

class ClapTrap
{
	private:
		static unsigned int const _initHitPoints = 10;
		static unsigned int const _initEnergyPoints = 10;
		static unsigned int const _initAttackDamage = 0;

	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	
	public:
		ClapTrap(void);
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap &other);
		ClapTrap &operator=(const ClapTrap &other);
		~ClapTrap();

		virtual void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		unsigned int	getHitPoints() const;
		unsigned int	getEnergyPoints() const;
		unsigned int	getAttackDamage() const;

		bool	checkHitPoints(void);
		bool	checkEnergyPoints(void);
};
