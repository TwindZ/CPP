#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>

class Fixed
{
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed const& fixed);
		Fixed & operator=(Fixed & rawBits);
		int getRawBits(void)const;
		void setRawBits(int const raw);

	private:
		int const static _size = 8;
		int _rawBits;
};

std::ostream & operator<<(std::ostream & o, Fixed & rawBits);

#endif