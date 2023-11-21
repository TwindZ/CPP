#include "../inc/PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

PresidentialPardonForm::PresidentialPardonForm(): AForm("", 1, 1), _target("")
{
	cout << "PresidentialPardonForm constructor call" << endl;
}

PresidentialPardonForm::PresidentialPardonForm(string const& target):
AForm("PresidentialPardonForm", 25, 5), _target(target)
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
	(void) copy;
	cout << "PresidentialPardonForm assignement call" << endl;
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

void PresidentialPardonForm::print()const
{
	string signstatus("Not sign");
	if(getIsSign())
		signstatus = "Signed";
	cout << "Form name : " << getName() << endl;
	cout << "Target : " << getTarget() << endl;
	cout << "Sign status : " << signstatus << endl;
	cout << "Grade to sign : " << getGradeToSign() << endl;
	cout << "Grade to execute : " << getGradeToExec()<< endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor)const
{
	
	if(executor.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
	if(getIsSign() == false)
			throw AForm::NotSignedException();
	cout << _target << " a été pardonnée par Zaphod Beeblebrox." << endl;
}
