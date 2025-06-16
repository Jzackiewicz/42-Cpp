#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap bobixon("Bobixon");

	bobixon.attack("Rob");
	bobixon.takeDamage(5);
	bobixon.beRepaired(3);
	bobixon.highFivesGuys();
	bobixon.guardGate();
	bobixon.whoAmI();
    return 0;
}
