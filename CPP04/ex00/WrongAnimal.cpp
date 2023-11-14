#include "WrongAnimal.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

WrongAnimal::WrongAnimal(): _type("")
{
	cout << "WrongAnimal constructor called" << endl;
}
		
WrongAnimal::WrongAnimal(WrongAnimal const& wrongAnimal)
{
	cout << "WrongAnimal copy constructor called" << endl;
	*this = wrongAnimal;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const& wrongAnimal)
{
	cout << "WrongAnimal assignement called" << endl;
	if(this != &wrongAnimal)
	{
		_type = wrongAnimal._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called" << endl;
}

string const& WrongAnimal::getType()const
{
	return _type;
}

void WrongAnimal::makeSound()const
{
	cout << "WrongAnimal Class has no default sound..." << endl;
}




