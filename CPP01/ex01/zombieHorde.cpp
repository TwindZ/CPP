#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	Zombie *zombies = new Zombie[N];
	while(N > 0)
		zombies[--N].setName(name);
	return zombies;
}