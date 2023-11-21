#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

using std::string;

class RobotomyRequestForm : public AForm
{
	private:

		string const _target;
		RobotomyRequestForm();
		
	public:

		RobotomyRequestForm(string const& name, string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& Copy);
		RobotomyRequestForm & operator=(RobotomyRequestForm const& Copy);
		~RobotomyRequestForm();

		string const& getTarget()const;
		void execute(Bureaucrat const & executor)const;
};
std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const& form);

#endif