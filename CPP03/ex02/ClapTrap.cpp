#include "ClapTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

ClapTrap::ClapTrap()
{
	cout << "Default Constructor called" << endl;
}

ClapTrap::ClapTrap(string const& name):_name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	cout << "ClapTrap "<< name << " base constructor call !" << endl;
}

ClapTrap::ClapTrap(string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage):
_name(name), _hitPoints(hitPoints), _energyPoints(energyPoints), _attackDamage(attackDamage)
{
	cout << "ClapTrap "<< name << " constructor called with costum initialisation !" << endl;
}
		
ClapTrap::ClapTrap(ClapTrap const& clapTrap)
{
	*this = clapTrap;
}

ClapTrap const& ClapTrap::operator=(ClapTrap const& clapTrap)
{
	if(this != &clapTrap)
	{
		_name = clapTrap.getName();
		_hitPoints = clapTrap.getHitPoints();
		_energyPoints = clapTrap.getEnergyPoints();
		_attackDamage = clapTrap.getAttackDamage();
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap " << _name  << " destructor called"<< endl;
}

string const ClapTrap::getName()const
{
	return _name;
}

unsigned int ClapTrap::getHitPoints()const
{
	return _hitPoints;
}

unsigned int ClapTrap::getEnergyPoints()const
{
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage()const
{
	return _attackDamage;
}

void ClapTrap::attack(string const& target)
{
	if(_hitPoints > 0 && _energyPoints > 0)
	{
		cout << "ClapTrap " << _name << " attacks " << target;
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

void ClapTrap::takeDamage(unsigned int amount)
{
	if(_hitPoints > 0)
	{
		if(_hitPoints <= amount)
			_hitPoints = 0;
		else
			_hitPoints -= amount;
		cout << _name << " take " << amount << " damage !" << endl;
		
	}
	if(_hitPoints == 0)
			cout << _name << " is dead !" << endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hitPoints > 0)
	{
		cout << _name << " trying to repair " << amount << " hit points..."<< endl;
		if( _energyPoints > 0)
		{
			_hitPoints += amount;
			_energyPoints--;
			cout << _name << " repaired " << amount << " hit points !"<< endl;
		}
		else
			cout << _name << " can't repair because he has no energy !" << endl;
	}
	else
		cout << _name << " can't repair because he's dead !" << endl;
	
}

void ClapTrap::status()const
{
	cout << endl << "| " << _name;
	cout << " | Hp : " << _hitPoints;
	cout << " | Ep : " << _energyPoints;
	cout << " | Ad : " << _attackDamage << " |" << endl << endl;
}
