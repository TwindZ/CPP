#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"

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
	cout << CYAN << "create new ShrubberyCreationForm named xMas with target Home " << RESET << endl;
	xMas = new ShrubberyCreationForm("xMas", "Home");
	
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
	cout << CYAN << "create new PresidentialPardonForm named pardon with target John " << RESET << endl;
	pardon = new PresidentialPardonForm("pardon", "John");
	
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "Pardon info" << RESET << endl;
	cout << *pardon << endl;
	
	//###############################################################################################
	//							TEST ShrubberyCreationForm xMas
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob try to execute xMas" << RESET << endl;
	bureaucrat->executeForm(*xMas);
	
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Promoting Bob 20 grade" << RESET << endl;
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
	//							TEST PresidentialPardonForm Pardon
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "Pardon info" << RESET << endl;
	cout << *pardon << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Promoting Bob 125 grade" << RESET << endl;
	for(int i = 0; i < 125; i++)
		bureaucrat->promote();
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	cout << ORANGE << "-------------------------------------------------" << RESET << endl;
	cout << ORANGE << "Bob retry to execute pardon" << RESET << endl;
	bureaucrat->signForm(*pardon);
	bureaucrat->executeForm(*pardon);

	//###############################################################################################
	//							TEST 

	//###############################################################################################
	//							DELETING
	cout << CYAN << "-------------------------------------------------" << RESET << endl;
	cout << CYAN << "deleting everybody" << RESET << endl;
	delete bureaucrat;
	delete xMas;
	delete xMasCopy;

return 0;
}