#include "ScavTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

//-------------------------COPLIEN
ScavTrap::ScavTrap()
{
	cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage):
ClapTrap(name, hitPoints, energyPoints, attackDamage)
{
	cout << "ScavTrap Constructor called" << endl;
}
		
ScavTrap::ScavTrap(ScavTrap const& ScavTrap)
{
	*this = ScavTrap();
}

ScavTrap const& ScavTrap::operator=(ScavTrap const& scavTrap)
{
	if(this != &scavTrap)
	{
		ClapTrap::operator=(scavTrap);
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap destructor called" << endl;
}