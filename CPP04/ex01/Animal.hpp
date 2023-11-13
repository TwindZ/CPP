#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

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
		
		string getType()const;
		virtual void makeSound()const;
		virtual string getIdeas(int i);
		virtual Brain * getBrain();

};
#endif
