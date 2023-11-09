#include "Cat.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Cat::Cat(): Animal("Cat")
{
	cout << "Cat default constructor called" << endl;
}

		
Cat::Cat(Cat const& cat)
{
	*this = cat;
	cout << "Cat copy constructor called" << endl;
}

Cat & Cat::operator=(Cat const& cat)
{
	if(this != &cat)
	{
		cout << "Cat assignement called" << endl;
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





