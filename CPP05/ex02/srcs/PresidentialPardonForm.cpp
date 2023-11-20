#include "../inc/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(): AForm("", 1, 1), _target("")
{
	cout << "PresidentialPardonForm constructor call" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string const& name, string const& target):
AForm(name, 25, 5), _target(target)
{
	cout << "Overload PresidentialPardonForm constructor call" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& copy):
AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy._target)
{
	cout << "PresidentialPardonForm copy constructor call" << endl;
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const& copy)
{
	cout << "PresidentialPardonForm assignement call" << endl;
	if(this != &copy)
	{
		//TODO verifier operateur = ne fonctionne pas sur cette class
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	cout << "PresidentialPardonForm destructor call" << endl;
}

string const& PresidentialPardonForm::getTarget()const
{
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	
	if(executor.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
	if(getIsSign() == false)
			throw AForm::NotSignedException();
	cout << _target << " a été pardonnée par Zaphod Beeblebrox." << endl;
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const& form)
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