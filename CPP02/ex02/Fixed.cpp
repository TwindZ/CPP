#include "Fixed.hpp"

using std::cout;
using std::endl;

//----------------------------------------------------------------
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

std::ostream & operator<<(std::ostream & o, Fixed const& fixed)
{
	o << fixed.toFloat();
	return o;
}

//----------------------------------------------------------------
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
	return getRawBits() >> _fractionSize;
}

float Fixed::toFloat( void ) const
{
	return (float)(_rawBits / (float)( 1 << _fractionSize));
}

//----------------------------------------------------------------

Fixed & Fixed::operator++()
{
	++_rawBits;
	return *this;
}

Fixed & Fixed::operator--()
{
	--_rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed copy(*this);
	copy._rawBits = this->_rawBits++;
	return copy;
}

Fixed Fixed::operator--(int)
{
	Fixed copy(*this);
	copy._rawBits = this->_rawBits--;
	return copy;
}

//----------------------------------------------------------------
Fixed Fixed::operator+(Fixed const& n)const
{
	return Fixed(this->toFloat() + n.toFloat());
}

Fixed Fixed::operator-(Fixed const& n)const
{
	return Fixed(this->toFloat() - n.toFloat());
}

Fixed Fixed::operator*(Fixed const& n)const
{
	return Fixed(this->toFloat() * n.toFloat());
}

Fixed Fixed::operator/(Fixed const& n)const
{
	if(n.getRawBits() != 0)
		return Fixed(this->toFloat() / n.toFloat());
	else
		cout << "invalid division" << endl;
	return Fixed(0);
}

//----------------------------------------------------------------
bool Fixed::operator==(Fixed const& n)const
{
	if(this->getRawBits() == n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator!=(Fixed const& n)const
{
	if(this->getRawBits() != n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>(Fixed const& n)const
{
	if(this->getRawBits() > n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<(Fixed const& n)const
{
	if(this->getRawBits() < n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator>=(Fixed const& n)const
{
	if(this->getRawBits() >= n.getRawBits())
		return true;
	return false;
}

bool Fixed::operator<=(Fixed const& n)const
{
	if(this->getRawBits() <= n.getRawBits())
		return true;
	return false;
}

//----------------------------------------------------------------
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
