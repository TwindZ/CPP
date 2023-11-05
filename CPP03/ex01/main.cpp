#include <iostream>
#include "ClapTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ClapTrap bob("Bob");
	ClapTrap jack("Jack");
	
	bob.status();
	jack.status();
	
	bob.battle(jack);
	bob.beRepaired(10);

	bob.status();
	jack.status();

	jack.setAttackDamage(2);
	jack.battle(bob);
	bob.setAttackDamage(4);
	bob.battle(jack);

	bob.status();
	jack.status();

	bob.beRepaired(3);
	jack.battle(bob);
	jack.battle(bob);
	bob.battle(jack);

	bob.status();
	jack.status();

	bob.beRepaired(3);
	jack.battle(bob);
	jack.battle(bob);
	jack.battle(bob);
	jack.battle(bob);

	bob.status();
	jack.status();

	bob.beRepaired(5);
	jack.battle(bob);
	jack.battle(bob);

	bob.status();
	jack.status();

	jack.beRepaired(2);
	jack.beRepaired(2);
	jack.battle(bob);

	bob.status();
	jack.status();

	bob.battle(jack);
	jack.beRepaired(10);
	jack.battle(bob);

	bob.status();
	jack.status();
}