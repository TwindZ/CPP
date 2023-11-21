# include <iostream>
# include "../inc/Bureaucrat.hpp"
# include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Intern.hpp"

# define ORANGE "\033[38;5;208m"
# define GREEN "\033[38;5;46m"
# define CYAN "\033[38;5;51m"
# define YELLOW "\033[38;5;226m"
# define RESET "\033[0m"

using std::cout;
using std::endl;

int main()
{
	//VALID NAME : "shrubbery creation", "robotomy request", "presidential pardon"
	AForm *form1;
	cout << YELLOW << "-------------------------------------------------" << RESET << endl;
	cout << YELLOW << "Intern" << RESET << endl;
	Intern intern;
	cout << YELLOW << "-------------------------------------------------" << RESET << endl;
	cout << YELLOW << "Intern try create wrong form name" << RESET << endl;
	try
	{
		form1 = intern.makeForm("bird form", "Pitpit");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	cout << YELLOW << "-------------------------------------------------" << RESET << endl;
	cout << YELLOW << "Intern try to create robotomy request" << RESET << endl;
	try
	{
		form1 = intern.makeForm("robotomy request", "Bender");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "form1 info" << RESET << endl;
	form1->print();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Create bureaucrat Bob" << RESET << endl;
	Bureaucrat bob("Bob", 150);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute" << RESET << endl;
	bob.executeForm(*form1);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "promote Bob 105 grades" << RESET << endl;
	for(int i = 0; i < 105; i++)
		bob.promote();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute" << RESET << endl;
	bob.executeForm(*form1);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to sign" << RESET << endl;
	bob.signForm(*form1);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob retry to execute" << RESET << endl;
	bob.executeForm(*form1);
	cout << YELLOW << "-------------------------------------------------" << RESET << endl;
	cout << YELLOW << "Delete everythings" << RESET << endl;
	delete form1;

	return 0;
}