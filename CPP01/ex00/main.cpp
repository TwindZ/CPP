#include "Zombie.hpp"

int main()
{
	Zombie *zombie;
	Zombie zombie2("Bob");
	zombie2.announce();
	cout << endl;

	randomChump("Frankyboy");
	cout << endl;

	zombie = newZombie("Emman");
	zombie->announce();
	delete zombie;
	zombie = NULL;
	cout << endl;
}
