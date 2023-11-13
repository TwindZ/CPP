#include "Animal.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Animal::Animal(): _type("")
{
	cout << "Animal constructor called" << endl;
}
		
Animal::Animal(Animal const& animal)
{
	cout << "Animal copy constructor called" << endl;
	*this = animal;
}

Animal & Animal::operator=(Animal const& animal)
{
	cout << "Animal assignement called" << endl;
	if(this != &animal)
	{
		_type = animal._type;
	}
	return *this;
}

Animal::~Animal()
{
	cout << "Animal destructor called" << endl;
}

string const& Animal::getType()const
{
	return _type;
}

void Animal::makeSound()const
{
	cout << "Animal Class has no default sound..." << endl;
}
