#include "../inc/RobotomyRequestForm.hpp"

using std::cout;
using std::endl;

RobotomyRequestForm::RobotomyRequestForm(): AForm("", 1, 1), _target("")
{
	cout << "RobotomyRequestForm constructor call" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(string const& target):
AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	cout << "RobotomyRequestForm overload constructor call" << endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& copy):
AForm(copy.getName(), copy.getGradeToSign(), copy.getGradeToExec()), _target(copy._target)
{
	cout << "RobotomyRequestForm copy constructor call" << endl;
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const& copy)
{
	(void) copy;
	cout << "RobotomyRequestForm assignement call" << endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	cout << "RobotomyRequestForm destructor call" << endl;
}

string const& RobotomyRequestForm::getTarget()const
{
	return _target;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor)const
{
	
	if(executor.getGrade() > getGradeToExec())
			throw AForm::GradeTooLowException();
	if(getIsSign() == false)
			throw AForm::NotSignedException();
	std::srand(static_cast<unsigned int>(std::time(0)));
	int randomNumber = std::rand() % 100;
	cout << "zzzzzzzzzzzzzzzeeeeeeeeeeeeeeeeee......." << endl;
	if(randomNumber < 50)
		cout << _target << " has been robotomized !" << endl;
	else
		cout << _target << " robotomized fail !" << endl;
		
}

void RobotomyRequestForm::print()const
{
	string signstatus("Not sign");
	if(getIsSign())
		signstatus = "Signed";
	cout << "Form name : " << getName() << endl;
	cout << "Target : " << getTarget() << endl;
	cout << "Sign status : " << signstatus << endl;
	cout << "Grade to sign : " << getGradeToSign() << endl;
	cout << "Grade to execute : " << getGradeToExec()<< endl;
}
