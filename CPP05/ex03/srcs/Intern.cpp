#include "../inc/Intern.hpp"

using std::cout;
using std::endl;
using std::cerr;

Intern::Intern()
{
	cout << "Intern constructor call" << endl;
}

Intern::Intern(Intern const& copy)
{
	(void) copy;
	cout << "Intern copy constructor call" << endl;
}

Intern & Intern::operator=(Intern const& copy)
{
	(void) copy;
	cout << "Intern assignement call" << endl;
	return *this;
}

Intern::~Intern()
{
	cout << "Intern destructor call" << endl;
}

std::exception Intern::NoFormFoundException()const
{
	throw std::invalid_argument("Invalid form name !");
}

AForm * Intern::makeForm(string name, string target)const
{	
	int i;
	string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	for (i = 0; i < 3; i++)
	{
		if(name == names[i])
			break;
	}
	switch (i)
	{
		case 0:
			return new ShrubberyCreationForm(target);
		case 1:
			return new RobotomyRequestForm(target);
		case 2:
			return new PresidentialPardonForm(target);	
		case 3:
			throw NoFormFoundException();
	}
	return 0;
}