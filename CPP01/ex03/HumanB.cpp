#include "HumanB.hpp"

HumanB::HumanB(string name): _name(name), _weapon(NULL)
{
	cout << "HumanB constructor call with name : " << this->_name << endl;
}

HumanB::~HumanB()
{
	cout << "HumanB destructor call with name : " << this->_name << endl;
}

void HumanB::attack()
{
	if(this->_weapon != NULL)
		cout << this->_name << " attacks with their " << this->getWeapon()->getType() << endl;
	else
		cout << this->_name << " attacks with fist " << endl;
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