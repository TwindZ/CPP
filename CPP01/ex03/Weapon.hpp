#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Weapon
{
	public:

		Weapon( void );
		Weapon(string type);
		~Weapon( void );
		string const& getType()const;
		void setType(string type);

	private:

		string	_type;

};

#endif