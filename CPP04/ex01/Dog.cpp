#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Dog::Dog():_brain(nullptr)
{
	cout << "Dog constructor called" << endl;
	_type = "Dog";
	_brain = new Brain;
	for(int i = 0; i < 100; i++)
		_brain->setIdea(i, "I'm a dog");
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
		_brain = new Brain;
		_brain->operator=(*dog._brain);
	}
	return *this;
}

Dog::~Dog()
{
	delete _brain;
	cout << "Dog destructor called" << endl;
}

void Dog::makeSound()const
{
	cout << "Whoof Whooff" << endl;
}

string Dog::getIdeas(int i)
{
	return _brain->getIdeas(i);
}

Brain * Dog::getBrain()
{
	return _brain;
}