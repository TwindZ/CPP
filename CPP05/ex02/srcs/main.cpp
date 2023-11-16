#include <iostream>
#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

#define ORANGE "\033[38;5;208m"
#define GREEN "\033[38;5;46m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main()
{
	Bureaucrat *bureaucrat;
	Bureaucrat *bureaucratcopy;
	Form *form;
	Form *formcopy;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 25" << RESET << endl;
	bureaucrat = new Bureaucrat("Bob", 25);
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy from bureaucrat" << RESET << endl;
	bureaucratcopy = new Bureaucrat(*bureaucrat);
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << *bureaucratcopy << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "operator<< overload" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat and bureaucratcopy" << RESET << endl;
	delete bureaucratcopy;
	delete bureaucrat;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 25" << RESET << endl;
	bureaucrat = new Bureaucrat("Bob", 25);
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 34" << RESET << endl;
	bureaucratcopy = new Bureaucrat("John", 34);
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << *bureaucratcopy << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "assignation from bureaucrat to bureaucratcopy" << RESET << endl;
	*bureaucratcopy = *bureaucrat;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << *bureaucratcopy << endl;
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat and bureaucratcopy" << RESET << endl;
	delete bureaucratcopy;
	delete bureaucrat;

//----------/////////-------------//////////------------///////////------------///////
	
	try
	{
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 151" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 151);
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}

	try
	{
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 0" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 0);
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
	
//---------------////////////////---------------////////////////------------------//////////

	try
	{
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 1" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 1);
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat" << RESET << endl;
	delete bureaucrat;

	try
	{
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 150" << RESET << endl;
		bureaucrat = new Bureaucrat("John", 150);
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat" << RESET << endl;
	delete bureaucrat;

//----------------/////////////----------------//////////////----------------/////////////

	try
	{
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "Form creation grade sign : 0    grade execute : 150" << RESET << endl;
		form = new Form("form1", 0, 150);
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "form1 info" << RESET << endl;
		cout << *form << endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "Form creation grade sign : 151    grade execute : 150" << RESET << endl;
		form = new Form("form1", 151, 150);
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "form1 info" << RESET << endl;
		cout << *form << endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}

		try
	{
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "Form creation grade sign : 1    grade execute : 0" << RESET << endl;
		form = new Form("form1", 1, 0);
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "form1 info" << RESET << endl;
		cout << *form << endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "Form creation grade sign : 1    grade execute : 151" << RESET << endl;
		form = new Form("form1", 1, 151);
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "form1 info" << RESET << endl;
		cout << *form << endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "Form creation grade sign : 15   grade execute : 75" << RESET << endl;
		form = new Form("form1", 15, 75);
		cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
		cout << GREEN << "form1 info" << RESET << endl;
		cout << *form << endl;
	}
	catch(std::exception const& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << GREEN << "formcopy from form" << RESET << endl;
	formcopy = new Form(*form);
	
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << GREEN << "formcopy info" << RESET << endl;
	cout << *formcopy << endl;
	
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << GREEN << "delete formcopy" << RESET << endl;
	delete formcopy;

	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 150" << RESET << endl;
	bureaucrat = new Bureaucrat("John", 150);
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;

	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << *form << endl;
	try
	{
	cout << GREEN << "bureaucrat try to sign" << RESET << endl;
		bureaucrat->signForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << *form << endl;
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "promote bureaucrat 140 times" << RESET << endl;
	for(int i = 0; i < 140; i++)
		bureaucrat->promote();
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << *bureaucrat << endl;
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << *form << endl;
	cout << GREEN << "bureaucrat try to sign" << RESET << endl;
	bureaucrat->signForm(*form);
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	cout << *form << endl;
	cout << GREEN << "-----------------------------------------------------------------------" << RESET << endl;
	bureaucrat->signForm(*form);
	
	cout << ORANGE << "-----------------------------------------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureacrat and form" << RESET << endl;
	
	delete form;
	delete bureaucrat;


return 0;
}