#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;
int main()
{

	// Fixed a(8.9990000f);
	// Fixed b(9);
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed const b( Fixed( 8 ) / Fixed( 0 ) );
	cout << b << endl;
	// if(a == b)
	// 	cout << "true" << endl;
	// else
	// 	cout << "false" << endl;
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	// std::cout << Fixed::max( a, b ) << std::endl;
	return 0;
}