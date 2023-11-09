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
		Animal(string const& name);
		Animal(Animal const& animal);
		Animal & operator=(Animal const& animal);
		virtual ~Animal();
		
		string getType()const;
		virtual void makeSound()const;

};
#endif