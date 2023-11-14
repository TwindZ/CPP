#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>
#include "AAnimal.hpp"
#include "Brain.hpp"

using std::string;

class Cat: public AAnimal
{
	private:

		Brain *_brain;

	public:

		Cat();
		Cat(Cat const& cat);
		Cat & operator=(Cat const& cat);
		~Cat();

		void makeSound()const;
		string const& getIdeas(int const i)const;
		Brain * getBrain();

};
#endif