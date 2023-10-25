#include "Weapon.hpp"

Weapon::Weapon(string type): _type(type)
{
	cout << "Weapon constructor call" << endl;
}

Weapon::Weapon()
{
	cout << "Weapon constructor call" << endl;
}

Weapon::~Weapon()
{
	cout << "Weapon destructor call" << endl;
}

void Weapon::setType(string name)
{
	this->_type = name;
}

string const Weapon::getType()const
{
	return this->_type;
}