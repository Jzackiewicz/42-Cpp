#include "Zombie.hpp"
#include "Zombie.h"

int main(void)
{
	Zombie *zombs;

	zombs = zombieHorde(5, "dupa");

	delete [] zombs;

	return (0);
}
