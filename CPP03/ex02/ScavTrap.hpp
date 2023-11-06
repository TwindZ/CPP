#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

using std::string;

class ScavTrap : public ClapTrap
{
	private:
		bool _guardGate;
		ScavTrap();

	public:

		ScavTrap(string const& name);
		ScavTrap(ScavTrap const& scavTrap);
		ScavTrap const& operator=(ScavTrap const& scavTrap);
		~ScavTrap();

		bool getGuardGateStatus( void )const;
		void attack(string const& target);
		void guardGate( void );
		void status( void )const;
		void battle(ScavTrap & target);
};
#endif