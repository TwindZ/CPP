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
	*this = wrongAnimal;
	cout << "WrongAnimal copy constructor called" << endl;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const& wrongAnimal)
{
	if(this != &wrongAnimal)
	{
		_type = wrongAnimal._type;
		cout << "WrongAnimal assignement called" << endl;
	}
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called" << endl;
}

string WrongAnimal::getType()const
{
	return _type;
}

void WrongAnimal::makeSound()const
{
	cout << "WrongAnimal Class has no default sound..." << endl;
}




