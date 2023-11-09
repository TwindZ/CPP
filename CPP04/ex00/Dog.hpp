#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

using std::string;

class Dog: public Animal
{
	private:

		string type;

	public:

		Dog();
		Dog(Dog const& dog);
		Dog & operator=(Dog const& dog);
		~Dog();

		void makeSound()const;

};
#endif