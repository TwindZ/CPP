#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	Zombie zombie2("Bob");
	zombie2.announce();
	randomChump("Frankyboy");
	zombie = newZombie("Emman");
	zombie->announce();
	delete zombie;
	zombie = NULL;
}
