#include "../inc/Bureaucrat.hpp"

#include <iostream>
#include <exception>
#include <stdexcept>

using std::string;
using std::exception;
using std::cout;
using std::endl;

Bureaucrat::Bureaucrat()
{
	cout << "Bureaucrat constructor call" << endl;
}

Bureaucrat::Bureaucrat(string const name, unsigned int grade):_name(name), _grade(grade)
{
	if(grade < 1)
		throw GradeTooHighException();
	else if(grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(Bureaucrat const& copy):_name(copy._name), _grade(copy._grade)
{
	cout << "Bureaucrat copy constructor call" << endl;
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const& copy)
{
	cout << "Bureaucrat assignement call" << endl;
	if(this != &copy)
	{
		_grade = copy._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat()
{
	cout << "Bureaucrat destructor call" << endl;
}

string const Bureaucrat::getName()const
{
	return _name;
}

unsigned int Bureaucrat::getGrade()const
{
	return _grade;
}

void Bureaucrat::promote()
{
	if(_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::demote()
{

	if(_grade == 150)
		throw GradeTooLowException();
	_grade++;

}

void Bureaucrat::signForm(AForm & aform)
{
	try
	{
		aform.beSigned(*this);
		cout << _name << " signed " << aform.getName() << endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " couldn't sign " << aform.getName() << " because : " << e.what() << endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is to high !";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is to low !";
}

std::ostream & operator<<(std::ostream & o, Bureaucrat const& bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return o;
}