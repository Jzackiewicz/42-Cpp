#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main(void)
{
    DiamondTrap bobixon("Bobixon");
	DiamondTrap robixon(bobixon);


	bobixon.attack("Rob");
	bobixon.takeDamage(5);
	bobixon.beRepaired(3);
	bobixon.highFivesGuys();
	bobixon.guardGate();
	bobixon.whoAmI();
	bobixon = DiamondTrap("Robixon");
	bobixon.whoAmI();
	return 0;
}
