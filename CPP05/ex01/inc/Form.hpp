#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

using std::string;
using std::exception;

class Bureaucrat;

class Form
{
	private:
		
		string const _name;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExec;
		Form();
		Form & operator=(Form const& Copy); //bloquer car sinon on peut transferer la signature d'un form low level vers une high level

	public:
		Form(string const name, unsigned int gradeToSign, unsigned int gradeToExec);
		Form(Form const& Copy);
		~Form();

		string const& getName()const;
		bool getIsSign()const;
		unsigned int getGradeToExec()const;
		unsigned int getGradeToSign()const;

		void beSigned(Bureaucrat & bureaucrat);


	class GradeTooHighException : public exception
	{
		public:
			const char* what() const throw();

	};
	class GradeTooLowException : public exception
	{
		public:
			const char* what() const throw();
	};
	class AlreadySignedException : public exception
	{
		public:
			const char* what() const throw();
	};
};
std::ostream & operator<<(std::ostream & o, Form const& form);

#endif