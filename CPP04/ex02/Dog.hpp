#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

using std::string;

class Dog: public AAnimal
{
	private:

		Brain *_brain;

	public:

		Dog();
		Dog(Dog const& dog);
		Dog & operator=(Dog const& dog);
		~Dog();

		void makeSound()const;
		string getIdeas(int i);
		Brain * getBrain();
};
#endif