#include "Zombie.hpp"

int main()
{
	Zombie *horde;
	int N = 9;
	string name = "Charlo";

	horde = zombieHorde(N, name);
	while(N > 0)
		horde[--N].announce();
	delete [] horde;
	return 0;
}
