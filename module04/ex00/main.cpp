#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal anim = Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat("Filemon");
	const WrongAnimal* wrongCat = new WrongCat("Bonifacy");

	std::cout << "Animal: " << anim.getType() << ", Dog: " << dog->getType() << ", Cat: " << cat->getType() << ", WrongCat: " << wrongCat->getType() << std::endl;
	anim.makeSound();
	dog->makeSound();
	cat->makeSound();
	wrongCat->makeSound();

	delete dog;
	delete cat;
	delete wrongCat;
	return 0;
}