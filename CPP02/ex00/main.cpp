#include "Fixed.hpp"
#include <iostream>

using std::cout;
int main()
{
	Fixed fixed1;
	Fixed fixed2;
	fixed1.setRawBits(0);
	fixed2.setRawBits(3);
	fixed1 = fixed2;
	cout << fixed1;
}