#include "Harl.hpp"

Harl::Harl()
{

}
Harl::~Harl()
{

}

void	Harl::debug()
{
	cout << "[ DEBUG ]" << endl ;
	cout << "I love having extra bacon for my 7XL-double-cheese-triple";
	cout << "-pickle-specialketchup burger. I really do !" << endl;
	cout << endl ;
}
void	Harl::info()
{
	cout << "[ INFO ]" << endl ;
	cout << "I cannot believe adding extra bacon costs more money. ";
	cout << "You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << endl;
	cout << endl ;
}
void	Harl::warning()
{
	cout << "[ WARNING ]" << endl ;
	cout << "I think I deserve to have some extra bacon for free. ";
	cout << "I’ve been coming for years whereas you started working here since last month." << endl;
	cout << endl ;
}
void	Harl::error()
{
	cout << "[ ERROR ]" << endl ;
	cout << "This is unacceptable ! I want to speak to the manager now." << endl;
	cout << endl ;
}

void	Harl::complain(string level)
{
	typedef void (Harl::*functionPtr)();
	
	functionPtr func[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++)
	{
		if(level == levels[i])
			(this->*func[i])();
	}
}