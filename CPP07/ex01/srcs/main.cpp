#include <iostream>
#include "../inc/iter.hpp"

using std::string;
using std::cout;
using std::endl;

int main()
{
	string arraystr[4] = {"allo", "bonjour", "blabla", "neige"};
	float arrayfloat[4] = {0.6f, 1.6f, 2.4f, 3.56f};
	float arrayint[4] = {14, 16, 218, 300};
	iter(arraystr, 4, print);
	iter(arraystr, 4, patate);
	iter(arraystr, 4, print);
	cout << "###############################" << endl;
	iter(arrayfloat, 4, print);
	iter(arrayfloat, 4, add);
	iter(arrayfloat, 4, print);
	cout << "###############################" << endl;
	iter(arrayint, 4, print);
	iter(arrayint, 4, add);
	iter(arrayint, 4, print);


	return (0);
}