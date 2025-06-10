#include "Zombie.hpp"
#include "Zombie.h"

int main(void)
{
	Zombie *zomb;

	zomb = newZombie("test2");
	randomChump("test");

	delete zomb;

	return (0);
}
