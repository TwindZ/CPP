#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

using std::cout;
using std::endl;
void test(Animal const& animal)
{
	animal.makeSound();
}

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	cout << endl << endl;

	test(*i);
	test(*j);
	test(*meta);

	cout << endl << endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();
	
	Brain brain;
	cout << "idea brain idea 8 address" << &brain.getIdea(8) << endl;
	Brain brain2(brain);
	cout << "idea brain2 idea 8 address" << &brain2.getIdea(8) << endl;

	delete meta;
	delete i;
	delete j;
	delete meta2;
	delete i2;

return 0;
}