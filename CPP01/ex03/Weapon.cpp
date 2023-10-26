#include "Weapon.hpp"

Weapon::Weapon(string type): _type(type)
{
	cout << "Weapon constructor call with type : " << this->_type << endl;
}

Weapon::~Weapon()
{
	cout << "Weapon destructor call" << endl;
}

void Weapon::setType(string name)
{
	cout << "Weapon change from \"" << _type << "\" to \"" << name << "\"" << endl;
	this->_type = name;
}

string const Weapon::getType()const
{
	return this->_type;
}