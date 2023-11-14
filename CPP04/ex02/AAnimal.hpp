#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

using std::string;

class AAnimal
{
	protected:

		string _type;

	public:

		AAnimal();
		AAnimal(AAnimal const& animal);
		AAnimal & operator=(AAnimal const& animal);
		virtual ~AAnimal();
		
		string const& getType()const;
		virtual void makeSound()const = 0;
		virtual string const& getIdeas(int const i)const = 0;
		virtual Brain * getBrain() = 0;

};
#endif
