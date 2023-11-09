#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

using std::string;

class FragTrap : public ClapTrap
{
	private:
		FragTrap();

	public:

		FragTrap(string const& name);
		FragTrap(FragTrap const& fragTrap);
		FragTrap & operator=(FragTrap const& fragTrap);
		~FragTrap();

		void highFivesGuys(void);
};
#endif