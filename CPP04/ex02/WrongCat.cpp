#include "WrongCat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

WrongCat::WrongCat()
{
	_type = "Cat";
	cout << "WrongCat constructor called" << endl;
}

WrongCat::WrongCat(WrongCat const& wrongCat)
{
	*this = wrongCat;
	cout << "WrongCat copy constructor called" << endl;
}

WrongCat & WrongCat::operator=(WrongCat const& wrongCat)
{
	if(this != &wrongCat)
	{
		WrongAnimal::operator=(wrongCat);
		cout << "WrongCat assignement called" << endl;
	}
	return *this;
}

WrongCat::~WrongCat()
{
	cout << "WrongCat destructor called" << endl;
}
