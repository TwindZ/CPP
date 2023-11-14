#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

using std::string;

class WrongCat: public WrongAnimal
{

	public:

		WrongCat();
		WrongCat(WrongCat const& wrongCat);
		WrongCat & operator=(WrongCat const& wrongCat);
		~WrongCat();

};
#endif