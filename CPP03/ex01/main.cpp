#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

using std::cout;
using std::endl;
int main()
{
	ScavTrap scavTrap("John", 10, 10, 10);
	cout << scavTrap.getName() << endl;
	cout << scavTrap.getHitPoints() << endl;
	cout << scavTrap.getEnergyPoints() << endl;
	cout << scavTrap.getAttackDamage() << endl;
}