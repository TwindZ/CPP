#include <iostream>
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Brain.hpp"

#define ORANGE "\033[38;5;208m"
#define RESET "\033[0m"

using std::cout;
using std::endl;
void test(Animal const& animal)
{
	animal.makeSound();
}
int main()
{
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "NEW ANIMAL meta" << RESET << endl;
	const Animal* meta = new Animal();
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "NEW CAT i" << RESET << endl;
	const Animal* i = new Cat();
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "NEW DOG j" << RESET << endl;
	const Animal* j = new Dog();
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "GETTYPE i et j" << RESET << endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "MAKESOUND i j meta" << RESET << endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "MAKESOUND DANS UNE FONCTION PASSER COMME ANIMAL" << RESET << endl;
	test(*i);
	test(*j);
	test(*meta);

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "WRONG ANIMAL meta2" << RESET << endl;
	const WrongAnimal* meta2 = new WrongAnimal();

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "WRONG CAT i2" << RESET << endl;
	const WrongAnimal* i2 = new WrongCat();

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "GETTYPE meta2 i2" << RESET << endl;
	std::cout << meta2->getType() << " " << std::endl;
	std::cout << i2->getType() << " " << std::endl;

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "MAKESOUND meta2 i2" << RESET << endl;
	meta2->makeSound();
	i2->makeSound();

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "NOUVEAU CAT cat1" << RESET << endl;
	Cat cat1;

	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "IDEA 3 DE cat1" << RESET << endl;
	cout << cat1.getIdeas(3) << endl;
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "CHANGE L'IDEA 3 DE cat1 pour ahhahaah" << RESET << endl;
	cat1.getBrain()->setIdea(3, "ahhahaah");
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "COPIE cat1 NOUVEAU CAT cat2" << RESET << endl;
	Cat cat2(cat1);
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "IDEA 3 DE cat2" << RESET << endl;
	cout << cat2.getIdeas(3) << endl;
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "FILL ARRAY ANIMAL WITH 2 CAT AND 2 DOGS " << RESET << endl;
	Animal *(animal[4]);
	for(int i = 0; i < 4; i++)
	{
		if(i < 2)
			animal[i] = new Cat;
		else
			animal[i] = new Dog;
			cout << endl;
	}
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "IDEA 6 FROM ANIMAL 1" << RESET << endl;
	cout << animal[1]->getIdeas(6) << endl;
	cout << ORANGE << "CHANGE IDEA 6 FROM ANIMAL 1 FOR : maybe im not a cat" << RESET << endl;
	animal[1]->getBrain()->setIdea(6, "maybe im not a cat");
	cout << ORANGE << "IDEA 6 FROM ANIMAL 1" << RESET << endl;
	cout << animal[1]->getIdeas(6) << endl;
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "DELETE ANIMAL ARRAY" << RESET << endl;
	for(int i = 0; i < 4; i++)
	{
		delete animal[i];
		animal[i] = 0;
		cout << endl;

	}
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "DELETE META I J META2 I2" << RESET << endl;
	delete meta;
	cout << endl;
	delete i;
	cout << endl;
	delete j;
	cout << endl;
	delete meta2;
	cout << endl;
	delete i2;
	cout << endl;
	meta = 0;
	i = 0;
	j = 0;
	meta2 = 0;
	i2 = 0;
	
	cout << ORANGE << "------------------------------------------------" << RESET << endl;
	cout << ORANGE << "DESTRUCTOR CAT1 CAT2" << RESET << endl;

return 0;
}