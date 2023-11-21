#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <exception>
# include "../inc/AForm.hpp"
# include "../inc/ShrubberyCreationForm.hpp"
# include "../inc/PresidentialPardonForm.hpp"
# include "../inc/RobotomyRequestForm.hpp"

class Intern
{
	public:

		Intern();
		Intern(Intern const& Copy);
		Intern & operator=(Intern const& Copy);
		~Intern();

		AForm * makeForm(string name, string target)const;
		std::exception NoFormFoundException()const;

};

#endif