#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat
{
	private:

	public:

		Bureaucrat();
		Bureaucrat(Bureaucrat const& Copy);
		Bureaucrat & operator=(Bureaucrat const& Copy);
		~Bureaucrat();

};

#endif