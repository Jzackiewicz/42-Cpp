#pragma once

#include "string"

class	Weapon
{
	private:
		std::string	_type;

	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string	getType(void) const;
		std::string	setType(void);
};

class HumanA
{
	private:
		std::string _name;
		Weapon		_weapon;

	public:
		HumanA(Weapon weap);
		~HumanA(void);
		
		void	attack(void);
		void	setWeapon(Weapon weapon);
};

class HumanB
{
	private:
		std::string _name;
		Weapon		_weapon;

	public:
		HumanB();
		~HumanB(void);
		
		void	attack(void);
		void	setWeapon(Weapon weapon);
};