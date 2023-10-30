#include "Zombie.hpp"

Zombie::Zombie() : _name("Zombie")
{
	cout << "Zombie constructor call" << endl;
}

Zombie::Zombie(string name) : _name(name)
{
	cout << "Zombie constructor call with name :"<< this->_name << endl;
}

Zombie::~Zombie()
{
	cout << "Zombie destructor call with name :" << this->_name << endl;
}

// void	Zombie::setName(string name)
// {
// 	this->_name = name;
// }

// string	const Zombie::getName()const
// {
// 	return this->_name;
// }

void	Zombie::announce()const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}