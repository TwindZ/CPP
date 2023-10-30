#include "HumanB.hpp"

HumanB::HumanB(string name): _name(name)
{
	cout << "HumanB constructor call with name : " << this->_name << endl;
}

HumanB::~HumanB()
{
	cout << "HumanB destructor call with name : " << this->_name << endl;
}

void HumanB::attack()
{
	cout << this->_name << " attacks with their " << this->getWeapon()->getType() << endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	cout << this->_name << " got " << _weapon->getType() << endl;
}

Weapon const* HumanB::getWeapon()const
{
	return (this->_weapon);
}