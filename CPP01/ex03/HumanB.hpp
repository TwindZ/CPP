#ifndef HUMANB_HPP
# define HUMANB_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanB
{
	public:

		HumanB(string name);
		~HumanB( void );
		void setWeapon(Weapon &weapon);
		void attack();
		Weapon *getWeapon();

	private:

		string _name;
		Weapon* _weapon;

};

#endif