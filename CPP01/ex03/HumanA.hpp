#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

using std::cout;
using std::endl;
using std::string;

class HumanA
{
	public:

		HumanA(string Name, Weapon *weapon);
		~HumanA( void );
		void attack();
		Weapon *getWeapon();
	private:

		string _name;
		Weapon *_weapon;

};

#endif