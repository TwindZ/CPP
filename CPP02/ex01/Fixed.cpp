#include "Fixed.hpp"

using std::cout;
using std::endl;

Fixed::Fixed(): _rawBits(0)
{
	cout << "Default constructor call" << endl;
}

Fixed::Fixed(int const intNum): _rawBits(intNum << _fractionSize)
{
	cout << "Int constructor call" << endl;
}

Fixed::Fixed(float const floatNum)
{
	_rawBits = (std::roundf(floatNum * (1 << _fractionSize)));
	cout << "Float constructor call" << endl;
}

Fixed::Fixed(Fixed const& fixed)
{
	cout << "Copy constructor call" << endl;
	*this = fixed;
}

Fixed const& Fixed::operator=(Fixed const& fixed)
{
	cout << "Copy assignment operator called" << endl;
	if(&fixed != this)
		_rawBits = fixed.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	cout << "Destructor call" << endl;
}

int Fixed::getRawBits()const
{
	return _rawBits;
}

void Fixed::setRawBits(int const raw)
{
	_rawBits = raw;
}

int Fixed::toInt( void ) const
{
	return getRawBits() >> this->_fractionSize;
}

float Fixed::toFloat( void ) const
{
	return (float)(_rawBits / (float)( 1 << _fractionSize));
}

std::ostream & operator<<(std::ostream & o, Fixed const& fixed)
{

	o << fixed.toFloat();
	return o;
}