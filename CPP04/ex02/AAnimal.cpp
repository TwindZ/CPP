#include "AAnimal.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

AAnimal::AAnimal(): _type("")
{
	cout << "AAnimal constructor called" << endl;
}
		
AAnimal::AAnimal(AAnimal const& aanimal)
{
	cout << "AAnimal copy constructor called" << endl;
	*this = aanimal;
}

AAnimal & AAnimal::operator=(AAnimal const& aanimal)
{
	cout << "AAnimal assignement called" << endl;
	if(this != &aanimal)
	{
		_type = aanimal._type;
	}
	return *this;
}

AAnimal::~AAnimal()
{
	cout << "AAnimal destructor called" << endl;
}

string const& AAnimal::getType()const
{
	return _type;
}

