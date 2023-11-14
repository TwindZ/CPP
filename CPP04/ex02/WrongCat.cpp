#include "WrongCat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

WrongCat::WrongCat()
{
	cout << "WrongCat constructor called" << endl;
	_type = "Cat";
}

		
WrongCat::WrongCat(WrongCat const& wrongCat)
{
	cout << "WrongCat copy constructor called" << endl;
	*this = wrongCat;
}

WrongCat & WrongCat::operator=(WrongCat const& wrongCat)
{
	cout << "WrongCat assignement called" << endl;
	if(this != &wrongCat)
	{
		WrongAnimal::operator=(wrongCat);
	}
	return *this;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called" << endl;
}
