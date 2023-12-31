#include "Cat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Cat::Cat()
{
	cout << "Cat constructor called" << endl;
	_type = "Cat";
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
		Animal::operator=(cat);
	}
	return *this;
}

Cat::~Cat()
{
	cout << "Cat destructor called" << endl;
}

void Cat::makeSound()const
{
	cout << "Meeeow Rrrrr Rrrr Rrr" << endl;
}
