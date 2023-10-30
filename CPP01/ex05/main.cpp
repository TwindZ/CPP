#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "Usage : ./ex05 <level>" << endl;
		cout << "Level : DEBUG, INFO, WARNING or ERROR" << endl;
		return -1;
	}
	Harl harl;
	string level = argv[1];
	harl.complain(level);
	return 0;
}