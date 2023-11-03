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
		Fixed const& operator=(Fixed const& fixed);

		int getRawBits( void )const;
		void setRawBits(int const raw);
		float toFloat( void ) const;
		int toInt( void ) const;

		Fixed & operator++();
		Fixed & operator--();
		Fixed operator++(int);
		Fixed operator--(int);

		Fixed operator+(Fixed const& n)const;
		Fixed operator-(Fixed const& n)const;
		Fixed operator*(Fixed const& n)const;
		Fixed operator/(Fixed const& n)const;

		bool operator==(Fixed const& n)const;
		bool operator!=(Fixed const& n)const;
		bool operator>(Fixed const& n)const;
		bool operator<(Fixed const& n)const;
		bool operator<=(Fixed const& n)const;
		bool operator>=(Fixed const& n)const;
		
		static Fixed const& min(Fixed const& fixed1, Fixed const& fixed2);
		static Fixed const& max(Fixed const& fixed1, Fixed const& fixed2);
		static Fixed & min(Fixed & fixed1, Fixed & fixed2);
		static Fixed & max(Fixed & fixed1, Fixed & fixed2);

	private:

		int const static _fractionSize = 8;
		int _rawBits;
};

std::ostream & operator<<(std::ostream & o, Fixed const& fixed);

#endif