#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    FragTrap bobix("Bobix");
	ClapTrap robson("Rob");

	bobix.attack("Rob");
	robson.takeDamage(9);
	robson.beRepaired(10);
	bobix.highFivesGuys();
	robson.attack("Bobix");
	bobix.takeDamage(100);
	bobix.beRepaired(50);
    return 0;
}
