#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon &weapon): _name(name), _weapon(weapon)
{
	cout << "HumanA constructor call with name " << this->_name 
	<< " and weapon type " << this->_weapon.getType() << endl;
}

HumanA::~HumanA()
{
	cout << "HumanA destructor call" << endl;
}

void HumanA::attack()
{
	cout << this->_name << " attacks with their " << this->getWeapon().getType() << endl;
}

Weapon& HumanA::getWeapon()
{
	return this->_weapon;
}
