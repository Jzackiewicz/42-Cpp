#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(std::string name): _name(name) {}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " has been destructed." << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::randomChump( std::string name )
{
	Zombie	new_zombie(name);

	new_zombie.announce();
}