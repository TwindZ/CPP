#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ScavTrap john("John");
	john.status();

	ScavTrap johncopy(john);
	johncopy.status();

	ScavTrap bob("Bob");

	john.status();
	bob.status();

	john.guardGate();

	john.battle(john);

	john.status();
	bob.status();
	bob.battle(john);
	
	john.status();
	bob.status();

	bob = john;
	john.status();
	bob.status();
	bob.guardGate();
	john.status();
	bob.status();

	
}