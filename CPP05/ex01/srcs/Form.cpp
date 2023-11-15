#include "Form.hpp"

using std::cout;
using std::endl;

Form::Form()
{
	cout << "Form constructor called" << endl;
}

Form::Form(Form const& copy)
{
	cout << "Form copy constructor called" << endl;
	*this = copy;
}

Form & Form::operator=(Form const& copy)
{
	cout << "Form assignement called" << endl;
	if(this != &copy)
	{
		/* ADD PRIVATES */
	}
	return *this;
}

Form::~Form()
{
	cout << "Form destructor called" << endl;
}