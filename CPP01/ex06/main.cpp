#include "Harl.hpp"

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "Usage : ./ex06 <filter>" << endl;
		cout << "Filters : DEBUG, INFO, WARNING or ERROR" << endl;
		return -1;
	}
	Harl harl;
	string filter = argv[1];
	harl.complain(filter);
	return 0;
}