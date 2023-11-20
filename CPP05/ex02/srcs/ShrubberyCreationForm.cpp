#include "../inc/ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::ofstream;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", 150, 150), _target("")
{
	cout << "ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string const& name, string const& target):
AForm(name, 145, 137), _target(target)
{
	//va devenir fonction execute
	ofstream ofs(target + "_shrubbery");

	for(int i = 0; i < 10; i++)
	{
		ofs << "             *" << endl;
		ofs << "            /.\\" << endl;
		ofs << "           /..'\\" << endl;
		ofs << "           /'.'\\" << endl;
		ofs << "          /.''.'\\" << endl;
		ofs << "          /.'.'.\\" << endl;
		ofs << "    '\"\"\"\"/'.''.'.\\\"'\"'\"" << endl;
		ofs << "         ^^^[_]^^^" << endl;
	}
	cout << "Overload ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy):
AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy._target)
{
	cout << "ShrubberyCreationForm copy constructor call" << endl;
	*this = copy;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	cout << "ShrubberyCreationForm assignement call" << endl;
	if(this != &copy)
	{
		//operateur= ne fonctionne pas sur cette class
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	cout << "ShrubberyCreationForm destructor call" << endl;
}

string const& ShrubberyCreationForm::getTarget()const
{
	return _target;
}

void ShrubberyCreationForm::beSigned(Bureaucrat & bureaucrat)
{
	(void) bureaucrat;
}

ofstream & ShrubberyCreationForm::drawXMasTree(ofstream & o)
{
	string buffer;

	
	return o;
}