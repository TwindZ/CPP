#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

using std::string;

class ClapTrap
{
	protected:
		string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;
		ClapTrap();
	
	public:

		ClapTrap(string const& name);
		ClapTrap(ClapTrap const& claptrap);
		ClapTrap(string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ClapTrap const& operator=(ClapTrap const& clapTrap);
		~ClapTrap();

		string const getName()const;
		unsigned int getHitPoints()const;
		unsigned int getEnergyPoints()const;
		unsigned int getAttackDamage()const;

		void attack(string const& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void status()const;
};
#endif