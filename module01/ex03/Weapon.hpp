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
		void		setType(std::string type);
};
