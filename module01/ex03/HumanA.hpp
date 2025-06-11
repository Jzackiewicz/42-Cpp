#pragma once

#include <string>
#include "Weapon.hpp"


class HumanA
{
	private:
		std::string _name;
		Weapon&		_weapon;

	public:
		HumanA(std::string name, Weapon& weap);
		~HumanA(void);
		
		void	attack(void);
};