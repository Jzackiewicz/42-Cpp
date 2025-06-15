#include "ClapTrap.hpp"

int main()
{
    ClapTrap claptrap("CLTP");

    claptrap.attack("target1");
    claptrap.takeDamage(3);
    claptrap.beRepaired(2);
    claptrap.attack("target2");
    claptrap.takeDamage(5);
    claptrap.beRepaired(4);

    return 0;
}
