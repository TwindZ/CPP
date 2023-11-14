#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

using std::string;

class WrongAnimal
{
	protected:

		string _type;

	public:

		WrongAnimal();
		WrongAnimal(string const& name);
		WrongAnimal(WrongAnimal const& WrongAnimal);
		WrongAnimal & operator=(WrongAnimal const& WrongAnimal);
		virtual ~WrongAnimal();
		
		string const& getType()const;
		virtual void makeSound()const;

};
#endif