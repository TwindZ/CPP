#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ScavTrap bob("Bob");
	bob.status();
	bob.takeDamage(3);
	ScavTrap john(bob);
	bob.status();
	john.status();
	bob.takeDamage(5);
	john = bob;

	bob.status();
	john.status();
	
	ScavTrap jack("Jack");
	
	bob.beRepaired(10);
	bob.status();

	bob.attack(jack.getName());
	jack.takeDamage(bob.getAttackDamage());
	bob.status();
	jack.status();

	bob.beRepaired(3);

	bob.status();
	jack.status();

	while(bob.getEnergyPoints() > 0)
		bob.attack(jack.getName());
	
	bob.status();
	jack.status();

	bob.attack(jack.getName());
	bob.beRepaired(10);
	jack.takeDamage(100);
	jack.attack(bob.getName());
	jack.beRepaired(2);
	bob.guardGate();
	jack.guardGate();
	
	bob.status();
	jack.status();

	ClapTrap dom("Dom");
	//dom.guardGate();
	dom.attack( "nothing" );

	cout << endl;
}