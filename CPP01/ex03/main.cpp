#include <iostream>
#include <string>
#include "HumanA.hpp"
#include "HumanB.hpp"

using std::endl;
using std::cout;
using std::string;

int main()
{

	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	cout << endl;
	cout << "************************************" << endl;
	cout << endl;
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
}
