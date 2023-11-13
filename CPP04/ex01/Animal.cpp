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
	*this = animal;
	cout << "Animal copy constructor called" << endl;
}

Animal & Animal::operator=(Animal const& animal)
{
	if(this != &animal)
	{
		_type = animal._type;
		cout << "Animal assignement called" << endl;
	}
	return *this;
}

Animal::~Animal()
{
	cout << "Animal destructor called" << endl;
}

string Animal::getType()const
{
	return _type;
}

void Animal::makeSound()const
{
	cout << "Animal Class has no default sound..." << endl;
}
