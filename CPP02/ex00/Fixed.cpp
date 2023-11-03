#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(): _rawBits(0)
{
	cout << "Default constructor call" << endl;
}

Fixed::Fixed(Fixed const& fixed)
{
	cout << "Copy constructor call" << endl;
	*this = fixed;
}

Fixed::~Fixed()
{
	cout << "Destructor call" << endl;
}

Fixed const& Fixed::operator=(Fixed const& fixed)
{
	cout << "Copy assignment operator called" << endl;
	if(&fixed != this)
		this->_rawBits = fixed.getRawBits();
	return *this;
}

int Fixed::getRawBits()const
{
	cout << "getRawBits member function call" << endl;
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}