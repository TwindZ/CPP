#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& fixed);
		Fixed(float const floatNum);
		Fixed(int const intNum);
		~Fixed();
		Fixed & operator=(Fixed const& rawBits);
		//manque les 2 post incre/decrementation;
		Fixed & operator++();
		Fixed & operator--();
		// void operator++(int);
		// void operator--(int);

		Fixed & operator+(Fixed const& n);
		Fixed & operator-(Fixed const& n);
		Fixed & operator*(Fixed const& n);
		Fixed & operator/(Fixed const& n); //TODO checker division pas 0

		bool operator==(Fixed const& n);
		bool operator!=(Fixed const& n);
		bool operator>(Fixed const& n);
		bool operator<(Fixed const& n);
		bool operator<=(Fixed const& n);
		bool operator>=(Fixed const& n);
		
		int getRawBits( void )const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

	private:
		int const static _fractionSize = 8;
		int _rawBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const& fixed);

#endif