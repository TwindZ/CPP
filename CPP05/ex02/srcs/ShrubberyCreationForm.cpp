#include "../inc/ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;

ShrubberyCreationForm::ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string const& name, string const& target):
AForm(name, 145, 137)
{
	cout << "Overload ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy)
{
	cout << "ShrubberyCreationForm copy constructor call" << endl;
	*this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	cout << "ShrubberyCreationForm assignement call" << endl;
	if(this != &copy)
	{
		/* ADD PRIVATES */
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm destructor call" << endl;
}