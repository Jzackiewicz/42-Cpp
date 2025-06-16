#include "ClapTrap.hpp"

int main()
{
    ClapTrap bob("Bob");
	ClapTrap rob("Rob");

    bob.attack("Rob");
    rob.takeDamage(3);
    rob.beRepaired(4);
    rob.attack("Bob");
    bob.takeDamage(11);
    bob.beRepaired(3);
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
	rob.attack("Bob");
    return 0;
}
