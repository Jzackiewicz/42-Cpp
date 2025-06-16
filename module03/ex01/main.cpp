#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap bobson("Bobson");
	ClapTrap robson("Robson");

	bobson.attack("Robson");
	robson.takeDamage(9);
	robson.beRepaired(10);
	bobson.guardGate();
	robson.attack("Bobson");
	bobson.takeDamage(100);
	bobson.beRepaired(50);
    return 0;
}
