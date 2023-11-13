#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"

using std::string;

class Cat: public Animal
{
	private:

		Brain *_brain;

	public:

		Cat();
		Cat(Cat const& cat);
		Cat & operator=(Cat const& cat);
		~Cat();

		void makeSound()const;
		string getIdeas(int i);
		Brain * getBrain();

};
#endif