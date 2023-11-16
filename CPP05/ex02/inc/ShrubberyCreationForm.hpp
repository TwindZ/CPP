#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "AForm.hpp"

using std::string;

class ShrubberyCreationForm : public AForm
{
	private:

		string const _target;
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(string const& name, string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& Copy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const& Copy);
		~ShrubberyCreationForm();

};

#endif