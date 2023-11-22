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
	int randomNumber = std::rand() % 2;
	cout << "zzzzzzzzzzzzzzzeeeeeeeeeeeeeeeeee......." << endl;
	if(randomNumber)
		cout << _target << " has been robotomized !" << endl;
	else
		cout << _target << " robotomized fail !" << endl;
		
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const& form)
{
	string signstatus("Not sign");
	if(form.getIsSign())
		signstatus = "Signed";
	o << "Form name : " << form.getName() << endl;
	o << "Target : " << form.getTarget() << endl;
	o << "Sign status : " << signstatus << endl;
	o << "Grade to sign : " << form.getGradeToSign() << endl;
	o << "Grade to execute : " << form.getGradeToExec();
	return o;
}