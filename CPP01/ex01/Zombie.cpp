#include "Zombie.hpp"

Zombie::Zombie()
{
	cout << "Zombie constructor call" << endl;
}

Zombie::~Zombie()
{
	cout << "Zombie destructor call" << endl;
}

void	Zombie::setName(string name)
{
	this->_name = name;
}

string	const Zombie::getName()const
{
	return this->_name;
}

void	Zombie::announce()const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}