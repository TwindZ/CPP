#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

using std::string;
using std::exception;

class Bureaucrat;

class AForm
{
	private:
		
		string const _name;
		bool _isSigned;
		unsigned int const _gradeToSign;
		unsigned int const _gradeToExec;
		AForm();

	public:
	
		AForm & operator=(AForm const& Copy);
		AForm(string const name, unsigned int gradeToSign, unsigned int gradeToExec);
		AForm(AForm const& Copy);
		virtual ~AForm();

		string const& getName()const;
		bool getIsSign()const;
		unsigned int getGradeToExec()const;
		unsigned int getGradeToSign()const;

		void beSigned(Bureaucrat & bureaucrat);
		virtual void execute(Bureaucrat const & executor)const = 0;
		virtual void print()const;

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
	
	class NotSignedException : public exception
	{
		public:
			const char* what() const throw();
	};
};
std::ostream & operator<<(std::ostream & o, AForm const& form);

#endif