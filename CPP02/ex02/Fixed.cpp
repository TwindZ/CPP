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

Fixed::~Fixed()
{
	cout << "Destructor call" << endl;
}

Fixed const& Fixed::operator=(Fixed const& fixed)
{
	cout << "Copy assignment operator called" << endl;
	if(&fixed != this)
		_rawBits = fixed.getRawBits();
	return *this;
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

Fixed & Fixed::operator++()
{
	this->setRawBits(_rawBits + 1);
	return *this;
}

Fixed & Fixed::operator--()
{
	this->setRawBits(_rawBits - 1);
	return *this;
}

Fixed Fixed::operator++(int n)
{
	(void) n;
	Fixed copy(*this);
	this->setRawBits(this->getRawBits() + 1);
	return copy;
}

Fixed Fixed::operator--(int n)
{
	(void) n;
	Fixed copy(*this);
	this->setRawBits(this->getRawBits() - 1);
	return copy;
}

Fixed & Fixed::operator+(Fixed const& n)
{
	this->setRawBits(this->getRawBits() + n.getRawBits());
	return *this;
}

Fixed & Fixed::operator-(Fixed const& n)
{
	this->setRawBits(this->getRawBits() - n.getRawBits());
	return *this;
}

Fixed & Fixed::operator*(Fixed const& n)
{
	this->setRawBits(((this->getRawBits() * n.getRawBits())) >> _fractionSize);
	return *this;
}

Fixed & Fixed::operator/(Fixed const& n)
{
	if(n.getRawBits() != 0)
		this->setRawBits((int)((float)(this->getRawBits()) / (float)(n.getRawBits()) * (1 << _fractionSize)));
	else
		cout << "invalid division" << endl;
	return *this;
}

bool Fixed::operator==(Fixed const& n)
{
	if(this->getRawBits() == n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const& n)
{
	if(this->getRawBits() != n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const& n)
{
	if(this->getRawBits() > n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const& n)
{
	if(this->getRawBits() < n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const& n)
{
	if(this->getRawBits() >= n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const& n)
{
	if(this->getRawBits() <= n.getRawBits())
		return true;
	return false;
}

Fixed const& Fixed::min(Fixed const& fixed1, Fixed const& fixed2)
{
	if(fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed const& Fixed::max(Fixed const& fixed1, Fixed const& fixed2)
{
	if(fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed & Fixed::min(Fixed & fixed1, Fixed & fixed2)
{
	if(fixed1.getRawBits() < fixed2.getRawBits())
		return fixed1;
	return fixed2;
}

Fixed & Fixed::max(Fixed & fixed1, Fixed & fixed2)
{
	if(fixed1.getRawBits() > fixed2.getRawBits())
		return fixed1;
	return fixed2;
}
