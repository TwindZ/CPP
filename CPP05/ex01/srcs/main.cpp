#include <iostream>
#include "../inc/Bureaucrat.hpp"

#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

using std::cout;
using std::endl;

int main()
{
	Bureaucrat *bureaucrat;
	Bureaucrat *bureaucratcopy;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 25" << RESET << endl;
	bureaucrat = new Bureaucrat("Bob", 25);
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << bureaucrat->getGrade() << endl;
	cout << bureaucrat->getName() << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy from bureaucrat" << RESET << endl;
	bureaucratcopy = new Bureaucrat(*bureaucrat);
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << bureaucratcopy->getGrade() << endl;
	cout << bureaucratcopy->getName() << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "operator<< overload" << RESET << endl;
	cout << *bureaucrat << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat and bureaucratcopy" << RESET << endl;
	delete bureaucratcopy;
	delete bureaucrat;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 25" << RESET << endl;
	bureaucrat = new Bureaucrat("Bob", 25);
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat info" << RESET << endl;
	cout << bureaucrat->getGrade() << endl;
	cout << bureaucrat->getName() << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucrat creation grade 34" << RESET << endl;
	bureaucratcopy = new Bureaucrat("John", 34);
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << bureaucratcopy->getGrade() << endl;
	cout << bureaucratcopy->getName() << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "assignation from bureaucrat to bureaucratcopy" << RESET << endl;
	*bureaucratcopy = *bureaucrat;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "bureaucratcopy info" << RESET << endl;
	cout << bureaucratcopy->getGrade() << endl;
	cout << bureaucratcopy->getName() << endl;
	
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat and bureaucratcopy" << RESET << endl;
	delete bureaucratcopy;
	delete bureaucrat;

//----------/////////-------------//////////------------///////////------------///////
	
	try
	{
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 151" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 151);
		cout << ORANGE << "----------------------------------------" << RESET << endl;
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
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 0" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 0);
		cout << ORANGE << "----------------------------------------" << RESET << endl;
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
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 1" << RESET << endl;
		bureaucrat = new Bureaucrat("Bob", 1);
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat" << RESET << endl;
	delete bureaucrat;

	try
	{
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat creation grade 150" << RESET << endl;
		bureaucrat = new Bureaucrat("John", 150);
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "bureaucrat info" << RESET << endl;
		cout << bureaucrat->getGrade() << endl;
		cout << bureaucrat->getName() << endl;

		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Promote" << RESET << endl;
		bureaucrat->promote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
		cout << ORANGE << "----------------------------------------" << RESET << endl;
		cout << ORANGE << "Demote" << RESET << endl;
		bureaucrat->demote();
		cout << bureaucrat->getGrade() << endl;
	}
	catch(std::exception const& e)
	{
		cout << e.what() << endl;
	}
	cout << ORANGE << "----------------------------------------" << RESET << endl;
	cout << ORANGE << "delete bureaucrat" << RESET << endl;
	delete bureaucrat;
return 0;
}