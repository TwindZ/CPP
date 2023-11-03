#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ClapTrap bob("Bob");
	
	bob.status();
	
	bob.attack("Jack");
	bob.beRepaired(10);
	bob.takeDamage(8);

	bob.status();

	bob.beRepaired(1);
	bob.beRepaired(1);
	bob.beRepaired(1);
	bob.beRepaired(1);
	bob.beRepaired(1);

	bob.status();

	bob.takeDamage(5);
	bob.attack("Jack");
	bob.attack("Jack");
	bob.attack("Jack");
	bob.attack("Jack");

	bob.status();

	bob.beRepaired(2);
	bob.takeDamage(2);

	bob.status();

	bob.attack("Jack");
	bob.beRepaired(10);
}