#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Zombie
{
	public:

		Zombie(string name);
		~Zombie( void );
		void	announce( void )const;

	private:

		Zombie( void );
		string	_name;

};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif