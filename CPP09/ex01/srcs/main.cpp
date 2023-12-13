#include <iostream>
#include "../inc/RPN.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if(argc != 2)
	{
		cout << "Error : Usage : RPN <\"ex: 9 8 + 5 - * 4 5 - + 6\">" << endl;
		std::exit(EXIT_FAILURE);
	}
	RPN rpn;
	rpn.execute(argv[1]);

	return 0;
}