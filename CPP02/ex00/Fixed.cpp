#include "Fixed.hpp"

using std::cout;

Fixed::Fixed(): _rawBits(0)
{

}

Fixed::Fixed(Fixed const& fixed)
{
	*this = fixed;
	return ;
}
Fixed::~Fixed()
{

}
Fixed & Fixed::operator=(Fixed & rawBits)
{
	this->_rawBits = rawBits.getRawBits();
	return *this;
}

int Fixed::getRawBits()const
{
	return this->_rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}


std::ostream & operator<<(std::ostream & o, Fixed & rawBits)
{
	rawBits.setRawBits(34);
	o << rawBits.getRawBits();
	return o;
}