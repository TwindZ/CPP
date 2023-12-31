#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Dog::Dog()
{
	cout << "Dog constructor called" << endl;
	_type = "Dog";
}
		
Dog::Dog(Dog const& dog)
{
	cout << "Dog copy constructor called" << endl;
	*this = dog;
}

Dog & Dog::operator=(Dog const& dog)
{
	cout << "Dog assignement called" << endl;
	if(this != &dog)
	{
		Animal::operator=(dog);
	}
	return *this;
}

Dog::~Dog()
{
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound()const
{
	cout << "Whoof Whooff" << endl;
}