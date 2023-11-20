#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
# include <fstream>
# include "AForm.hpp"

using std::string;
using std::ofstream;

class PresidentialPardonForm : public AForm
{
	private:

		string const _target;
		PresidentialPardonForm();

	public:
		PresidentialPardonForm(string const& name, string const& target);
		PresidentialPardonForm(PresidentialPardonForm const& Copy);
		PresidentialPardonForm & operator=(PresidentialPardonForm const& Copy);
		~PresidentialPardonForm();

		string const& getTarget()const;
		void execute(Bureaucrat const & executor)const;
};
std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const& form);

#endif