#include "Fixed.hpp"
#include <iostream>

using std::cout;
using std::endl;
int main()
{
	
	Fixed a;
	cout << "a :" << a << endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	cout << "b * :" << b << endl;
	Fixed const c( Fixed( 5.05f ) / Fixed( 2 ) );
	cout << "c / :" << c << endl;
	Fixed d( Fixed( 5.05f ) + Fixed( 2 ) );
	cout << "d + :" << d << endl;
	Fixed e( Fixed( 5.05f ) - Fixed( 2 ) );
	cout << "e - :" << e << endl;
	Fixed f = e;
	cout << "f = e : (f)" << f << endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << "max :" << Fixed::max( a, b ) << std::endl;
	std::cout << "min :" << Fixed::min( c, b ) << std::endl;
	std::cout << "max :" << Fixed::max( d, e ) << std::endl;
	std::cout << "min :" << Fixed::min( d, e ) << std::endl;

	a = 1;
	d = 4;
	e = 5;
	f = 6;
	std::cout << "a > b" << std::endl;
	if(a > b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "a < b" << std::endl;
	if(a < b)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "d >= e" << std::endl;
	if(d >= e)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "e <= e" << std::endl;
	if(e <= e)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "e == f" << std::endl;
	if(e == f)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "f != f" << std::endl;
	if(f != f)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	return 0;
}