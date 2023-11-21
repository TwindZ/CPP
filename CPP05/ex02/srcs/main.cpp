#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"

#define ORANGE "\033[38;5;208m"
#define GREEN "\033[38;5;46m"
#define CYAN "\033[38;5;51m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main()
{
	Bureaucrat *bureaucrat;
	ShrubberyCreationForm *xMas;
	ShrubberyCreationForm *xMasCopy;
	RobotomyRequestForm *robotomy;
	PresidentialPardonForm *pardon;
	
	//###############################################################################################
	//							BASE TEST
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "create new bureaucrat Bob grade 150" << RESET << endl;
	bureaucrat = new Bureaucrat("Bob", 150);
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "create new ShrubberyCreationForm with target Home " << RESET << endl;
	xMas = new ShrubberyCreationForm("Home");
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "xMas info" << RESET << endl;
	cout << *xMas << endl;
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "copy xMas to xMasCopy" << RESET << endl;
	xMasCopy = new ShrubberyCreationForm(*xMas);
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "xMascopy info" << RESET << endl;
	cout << *xMasCopy << endl;

	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "create new RobotomyRequestForm with target Killer " << RESET << endl;
	robotomy = new RobotomyRequestForm("Killer");
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "robotomy info" << RESET << endl;
	cout << *robotomy << endl;

	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "create new PresidentialPardonForm with target John " << RESET << endl;
	pardon = new PresidentialPardonForm("John");
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "Pardon info" << RESET << endl;
	cout << *pardon << endl;
	
	//###############################################################################################
	//							TEST ShrubberyCreationForm xMas
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute xMas" << RESET << endl;
	bureaucrat->executeForm(*xMas);
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Promoting Bob 20 grades" << RESET << endl;
	for(int i = 0; i < 20; i++)
		bureaucrat->promote();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob retry to execute xMas" << RESET << endl;
	bureaucrat->executeForm(*xMas);
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to sign" << RESET << endl;
	bureaucrat->signForm(*xMas);
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "xMas info" << RESET << endl;
	cout << *xMas << endl;
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob retry to execute xMas" << RESET << endl;
	bureaucrat->executeForm(*xMas);
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "File Home_shrubbery is created by xMas" << RESET << endl;

	//###############################################################################################
	//							TEST RobotomyRequestForm robotomy
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "robotomy info" << RESET << endl;
	cout << *robotomy << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Promoting Bob 90 grades" << RESET << endl;
	for(int i = 0; i < 90; i++)
		bureaucrat->promote();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob sign robotomy" << RESET << endl;
	bureaucrat->signForm(*robotomy);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute robotomy" << RESET << endl;
	bureaucrat->executeForm(*robotomy);

	//###############################################################################################
	//							TEST PresidentialPardonForm Pardon
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "Pardon info" << RESET << endl;
	cout << *pardon << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Promoting Bob 35 grades" << RESET << endl;
	for(int i = 0; i < 35; i++)
		bureaucrat->promote();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob sign pardon" << RESET << endl;
	bureaucrat->signForm(*pardon);
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute pardon" << RESET << endl;
	bureaucrat->executeForm(*pardon);

	//###############################################################################################
	//							DELETING
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "deleting everybody" << RESET << endl;
	delete bureaucrat;
	delete xMas;
	delete xMasCopy;
	delete robotomy;
	delete pardon;
	bureaucrat = 0;
	xMas = 0;
	xMasCopy = 0;
	robotomy = 0;
	pardon = 0;

return 0;
}