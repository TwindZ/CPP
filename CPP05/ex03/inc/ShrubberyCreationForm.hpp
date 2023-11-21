#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

using std::string;
using std::ofstream;

class ShrubberyCreationForm : public AForm
{
	private:

		string const _target;
		ShrubberyCreationForm();
	
	public:
		ShrubberyCreationForm(string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& Copy);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const& Copy);
		~ShrubberyCreationForm();

		string const& getTarget()const;
		void execute(Bureaucrat const & executor)const;
		void print()const;
};

#endif