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

		Zombie( void );
		~Zombie( void );
		void	setName(string name);
		string	const getName( void )const;
		void	announce( void )const;

	private:

		string	_name;

};

Zombie* zombieHorde( int N, std::string name );

#endif