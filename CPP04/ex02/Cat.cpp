#include "Cat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Cat::Cat():_brain(nullptr)
{
	cout << "Cat constructor called" << endl;
	_type = "Cat";
	_brain = new Brain;
	for(int i = 0; i < 100; i++)
		_brain->setIdea(i, "I'm a cat");
}

Cat::Cat(Cat const& cat)
{
	cout << "Cat copy constructor called" << endl;
	*this = cat;
}

Cat & Cat::operator=(Cat const& cat)
{
	cout << "Cat assignement called" << endl;
	if(this != &cat)
	{
		AAnimal::operator=(cat);
		_brain = new Brain(*cat._brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _brain;
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound()const
{
	cout << "Meeeow Rrrrr Rrrr Rrr" << endl;
}

string Cat::getIdeas(int i)
{
	return _brain->getIdeas(i);
}

Brain * Cat::getBrain()
{
	return _brain;
}
