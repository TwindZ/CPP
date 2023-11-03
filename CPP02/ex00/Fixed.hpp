#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <fstream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const& fixed);
		Fixed const& operator=(Fixed const& fixed);
		~Fixed();
		
		int getRawBits(void)const;
		void setRawBits(int const raw);

	private:
		int const static _fractionSize = 8;
		int _rawBits;
};

#endif