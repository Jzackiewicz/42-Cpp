#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Animal		**animals;
    int			animals_count;

	animals_count = 4;
	// Animal *test = new Animal(); -------> NOT POSSIBLE with pure virtual functions
	animals = new Animal*[animals_count];
	animals[0] = new Dog("dawg");
	animals[1] = new Cat("cawt");
	animals[2] = new Dog(*(static_cast<Dog*>(animals[0])));
	animals[3] = new Cat(*(static_cast<Cat*>(animals[1])));
	std::cout << "-------------------------------------" << std::endl;
	
	animals[0]->thinkAbout("eppy", 3);
	animals[2]->thinkAbout("zoomies", 3);

	for (int i = 0; i < 4; i++)
	{
		animals[i]->showThoughts();
		delete (animals[i]);
	}	
	delete [] (animals);

    return 0;
}