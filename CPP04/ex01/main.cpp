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
	// const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	// meta->makeSound();

	cout << endl << endl;

	test(*i);
	test(*j);
	// test(*meta);

	cout << endl << endl;

	const WrongAnimal* meta2 = new WrongAnimal();
	const WrongAnimal* i2 = new WrongCat();;
	std::cout << i2->getType() << " " << std::endl;
	i2->makeSound();
	meta2->makeSound();

	Cat cat1;
	cat1.getBrain()->setIdea(3, "ahhahaah");
	Cat cat2(cat1);
	cout << cat2.getIdeas(3) << endl << endl;

	Animal *(animal[20]);
	for(int i = 0; i < 20; i++)
	{
		if(i < 10)
			animal[i] = new Cat;
		else
			animal[i] = new Dog;
	}
	
	cout << endl << endl;
	cout << animal[12]->getIdeas(6) << endl;
	animal[12]->getBrain()->setIdea(6, "maybe im not a dog");
	cout << animal[12]->getIdeas(6) << endl;
	for(int i = 0; i < 20; i++)
	{
		delete animal[i];
		animal[i] = 0;
	}

	// delete meta;
	delete i;
	delete j;
	delete meta2;
	delete i2;
	// meta = 0;
	// i = 0;
	// j = 0;
	// meta2 = 0;
	// i2 = 0;

return 0;
}