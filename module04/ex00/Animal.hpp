#pragma once

#include <string>

class Animal
{
	private:
		std::string	_type;
	
	public:
		Animal(void);
		Animal(const std::string &type);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		void	make_sound(void);
};