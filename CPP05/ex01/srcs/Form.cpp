#include "../inc/Form.hpp"
#include "../inc/Bureaucrat.hpp"

using std::cout;
using std::endl;

Form::Form():_name("Private constructor"),
_isSigned(false), _gradeToSign(150), _gradeToExec(150)
{
	cout << "Form constructor call" << endl;
}

Form::Form(string const name, unsigned int gradeToSign, unsigned int gradeToExec):
_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	cout << "Form overload constructor call" << endl;

	if(_gradeToExec < 1 || _gradeToSign < 1)
		throw GradeTooHighException();
	else if(_gradeToExec > 150 || _gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& copy):_name(copy._name), _isSigned(copy._isSigned),
_gradeToSign(copy._gradeToSign), _gradeToExec(copy._gradeToExec)
{
	cout << "Form copy constructor call" << endl;
}

Form & Form::operator=(Form const& copy)
{
	cout << "Form assignement call" << endl;
	if(this != &copy)
	{
		_isSigned = copy._isSigned;
	}
	return *this;
}

Form::~Form()
{
	cout << "Form destructor call" << endl;
}

string const& Form::getName()const
{
	return _name;
}
bool Form::getIsSign()const
{
	return _isSigned;
}

unsigned int Form::getGradeToExec()const
{
	return _gradeToExec;
}
unsigned int Form::getGradeToSign()const
{
	return _gradeToSign;
}

void Form::beSigned(Bureaucrat & bureaucrat)
{
	if(bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	if(_isSigned == true)
		throw AlreadySignedException();
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is to high !";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is to low !";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Form already signed!";
}

std::ostream & operator<<(std::ostream & o, Form const& form)
{
	string signstatus("Not sign");
	if(form.getIsSign())
		signstatus = "Signed";
	o << "Form name : " << form.getName() << endl;
	o << "Sign status : " << signstatus << endl;
	o << "Grade to sign : " << form.getGradeToSign() << endl;
	o << "Grade to execute : " << form.getGradeToExec();

	return o;
}