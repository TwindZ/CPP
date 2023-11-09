#include "FragTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

FragTrap::FragTrap()
{
	cout << "FragTrap default constructor called" << endl;
}

FragTrap::FragTrap(string const& name):
ClapTrap(name, 100, 100, 30)
{
	cout << "FragTrap constructor called" << endl;
}
		
FragTrap::FragTrap(FragTrap const& fragTrap): ClapTrap(fragTrap)
{
	cout << "FragTrap copy constructor called" << endl;
}

FragTrap & FragTrap::operator=(FragTrap const& fragTrap)
{
	if(this != &fragTrap)
	{
		ClapTrap::operator=(fragTrap);
		cout << "FragTrap assignement called" << endl;
	}
	return *this;
}

FragTrap::~FragTrap()
{
	cout << "FragTrap destructor called" << endl;
}

void FragTrap::highFivesGuys(void)
{
	if(_hitPoints == 0)
		cout << _name << " can't high fives because he's dead !" << endl;
	else
		cout << "Who want an high fives guys ?" << endl;
}