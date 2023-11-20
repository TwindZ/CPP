#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

using std::cout;
using std::endl;

AForm::AForm():_name("Private constructor"),
_isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	cout << "AForm constructor call" << endl;
}

AForm::AForm(string const name, unsigned int gradeToSign, unsigned int gradeToExec):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	cout << "AForm overload constructor call" << endl;

	if(_gradeToExec < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if(_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& copy):_name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	cout << "AForm copy constructor call" << endl;
}

AForm & AForm::operator=(AForm const& copy)
{
	cout << "AForm assignement call" << endl;
	if(this != &copy)
	{
		_isSigned = copy._isSigned;
	}
	return *this;
}

AForm::~AForm()
{
	cout << "AForm destructor call" << endl;
}

string const& AForm::getName()const
{
	return _name;
}
bool AForm::getIsSign()const
{
	return _isSigned;
}

unsigned int AForm::getGradeToExec()const
{
	return _gradeToExec;
}
unsigned int AForm::getGradeToSign()const
{
	return _gradeToSign;
}

void AForm::beSigned(Bureaucrat & bureaucrat)
{
	if(bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	if(_isSigned == true)
		throw AlreadySignedException();
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is to high !";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is to low !";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Already signed !";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Not signed !";
}

std::ostream & operator<<(std::ostream & o, AForm const& form)
{
	o << "Form name : " << form.getName() << endl;
	o << "Sign status : " << form.getIsSign() << endl;
	o << "Grade to sign : " << form.getGradeToSign() << endl;
	o << "Grade to execute : " << form.getGradeToExec();

	return o;
}