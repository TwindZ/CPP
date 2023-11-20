#include "../inc/ShrubberyCreationForm.hpp"

using std::cout;
using std::endl;
using std::ofstream;

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("", 1, 1), _target("")
{
	cout << "ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(string const& name, string const& target):
AForm(name, 145, 137), _target(target)
{
	cout << "Overload ShrubberyCreationForm constructor call" << endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& copy):
AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy._target)
{
	cout << "ShrubberyCreationForm copy constructor call" << endl;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const& copy)
{
	cout << "ShrubberyCreationForm assignement call" << endl;
	if(this != &copy)
	{
		//TODO verifier operateur = ne fonctionne pas sur cette class
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor)const
{
	
	if(executor.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
	if(getIsSign() == false)
			throw AForm::NotSignedException();
		ofstream ofs(_target + "_shrubbery.txt");
	for(int i = 0; i < 10; i++)
	{
		ofs << endl;
		ofs << "             *" << endl;
		ofs << "            /.\\" << endl;
		ofs << "           /..'\\" << endl;
		ofs << "           /'.'\\" << endl;
		ofs << "          /.''.'\\" << endl;
		ofs << "          /.'.'.\\" << endl;
		ofs << "    '\"\"\"\"/'.''.'.\\\"'\"'\"" << endl;
		ofs << "         ^^^[_]^^^" << endl;
		ofs << endl;

	}
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const& form)
{
	//TODO trouve un moyen de call l'operator<< de la classe mere;
	//en attendant
	string signstatus("Not sign");
	if(form.getIsSign())
		signstatus = "Signed";
	o << "Form name : " << form.getName() << endl;
	o << "Target : " << form.getTarget() << endl;
	o << "Sign status : " << signstatus << endl;
	o << "Grade to sign : " << form.getGradeToSign() << endl;
	o << "Grade to execute : " << form.getGradeToExec();
	return o;
}