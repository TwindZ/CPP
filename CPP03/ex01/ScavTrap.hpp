#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

using std::string;

class ScavTrap : public ClapTrap
{
	private:
		ScavTrap();

	public:

		ScavTrap::ScavTrap(string const& name, unsigned int hitPoints, unsigned int energyPoints, unsigned int attackDamage);
		ScavTrap(ScavTrap const& scavTrap);
		ScavTrap const& operator=(ScavTrap const& scavTrap);
		~ScavTrap();

};
#endif