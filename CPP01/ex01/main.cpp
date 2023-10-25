#include "Zombie.hpp"

int main()
{

	Zombie *horde;
	int N = 18;
	string name = "Emman";

	horde = zombieHorde(N, name);
	while(N > 0)
		horde[--N].announce();
	delete [] horde;

}
