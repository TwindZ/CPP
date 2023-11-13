#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

using std::string;

class Animal
{
	protected:

		string _type;

	public:

		Animal();
		Animal(Animal const& animal);
		Animal & operator=(Animal const& animal);
		virtual ~Animal();
		
		string const& getType()const;
		virtual void makeSound()const;

};
#endif
