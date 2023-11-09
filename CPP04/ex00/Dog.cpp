#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Dog::Dog(): Animal("Dog")
{
	cout << "Dog default constructor called" << endl;
}
		
Dog::Dog(Dog const& dog)
{
	*this = dog;
	cout << "Dog copy constructor called" << endl;
}

Dog & Dog::operator=(Dog const& dog)
{
	if(this != &dog)
	{
		cout << "Dog assignement called" << endl;
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