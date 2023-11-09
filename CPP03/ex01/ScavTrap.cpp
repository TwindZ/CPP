#include "ScavTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ScavTrap::ScavTrap():_guardGate(false)
{
	cout << "ScavTrap default constructor called" << endl;
}

ScavTrap::ScavTrap(string const& name):
ClapTrap(name, 100, 50, 20), _guardGate(false)
{
	cout << "ScavTrap constructor called" << endl;
}
		
ScavTrap::ScavTrap(ScavTrap const& scavTrap): ClapTrap(scavTrap)
{
	_guardGate = scavTrap.getGuardGateStatus();
	cout << "ScavTrap copy constructor called" << endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const& scavTrap)
{
	if(this != &scavTrap)
	{
		ClapTrap::operator=(scavTrap);
		_guardGate = scavTrap.getGuardGateStatus();
		cout << "ScavTrap assignement called" << endl;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap " << _name << " destructor called" << endl;
}

bool ScavTrap::getGuardGateStatus()const
{
	return _guardGate;
}

void ScavTrap::attack(string const& target)
{
	if(_hitPoints > 0 && _energyPoints > 0)
	{
		cout << "ScavTrap " << _name << " attacks " << target;
		cout << ", causing " << _attackDamage << " points of damage !" << endl;
		_energyPoints--;
	}
	else
	{
		if(_hitPoints == 0)
			cout << _name << " can't attack because he's dead !" << endl;
		else
			cout << _name << " can't attack because he has no energy !" << endl;
	}
}

void ScavTrap::guardGate()
{
	if(_hitPoints > 0)
	{
		if(_guardGate == false)
		{
			_guardGate = true;
			cout << _name << " enter in guard gate mode !" << endl;
		}
		else
		{
			_guardGate = false;
			cout << _name << " exit guard gate mode !" << endl;
		}
	}
	else
			cout << _name << " can't guard gate because he's dead !" << endl;

}

void ScavTrap::status()const
{
	cout << endl << "| " << _name;
	cout << " | Hp : " << _hitPoints;
	cout << " | Ep : " << _energyPoints;
	cout << " | Ad : " << _attackDamage;
	cout << " | Guard : " << _guardGate << " |" << endl << endl;
}
