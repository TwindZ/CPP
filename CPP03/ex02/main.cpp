#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	FragTrap paul("Paul");
	paul.status();
	ScavTrap jay("Jay");
	jay.status();
	paul.highFivesGuys();
	jay.guardGate();
	// paul.guardGate();
	// jay.highFivesGuys();
	paul.attack(jay.getName());
	jay.takeDamage(paul.getAttackDamage());
	jay.attack(paul.getName());
	paul.takeDamage(jay.getAttackDamage());
	paul.status();
	jay.status();
}