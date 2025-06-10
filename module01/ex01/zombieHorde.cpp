#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie	*new_horde;

	new_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		new_horde[i].setName(name);
		new_horde->announce();
	}
	
	return (new_horde);
}
