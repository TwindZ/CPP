#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ClapTrap bob("Bob");
	bob.status();
	bob.takeDamage(3);
	ClapTrap john(bob);
	bob.status();
	john.status();
	bob.takeDamage(5);
	john = bob;

	bob.status();
	john.status();
	
	ClapTrap jack("Jack");
	john = jack = bob;
	cout << "ici ";
	john.status();
	bob.status();
	bob.beRepaired(10);
	bob.status();
	john.status();
	bob.attack(jack.getName());
	jack.takeDamage(bob.getAttackDamage());
	bob.status();

	bob.beRepaired(3);

	bob.status();
	jack.status();

	while(bob.getEnergyPoints() > 0)
		bob.attack(jack.getName());
	
	bob.status();
	jack.status();

	bob.attack(jack.getName());
	bob.beRepaired(10);
	jack.takeDamage(10);
	jack.attack(bob.getName());
	jack.beRepaired(2);
	
	bob.status();
	jack.status();
}