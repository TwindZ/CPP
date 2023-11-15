#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

using std::string;
using std::exception;

class Bureaucrat
{
	private:
		string const _name;
		unsigned int _grade;
		Bureaucrat();

	public:

		Bureaucrat(string const name, unsigned int grade);
		Bureaucrat(Bureaucrat const& Copy);
		Bureaucrat & operator=(Bureaucrat const& Copy);
		~Bureaucrat();

		string const getName()const;
		unsigned int getGrade()const;

		void promote();
		void demote();

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
};
std::ostream & operator<<(std::ostream & o, Bureaucrat const& bureaucrat);

#endif