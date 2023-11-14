#include "Bureaucrat.hpp"

using std::cout;
using std::endl;

Bureaucrat::Bureaucrat()
{
	cout << "Bureaucrat constructor called" << endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy)
{
	*this = copy;
	cout << "Bureaucrat copy constructor called" << endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& copy)
{
	if(this != &copy)
	{
		/* ADD PRIVATES */
		cout << "Bureaucrat assignement called" << endl;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor called" << endl;
}