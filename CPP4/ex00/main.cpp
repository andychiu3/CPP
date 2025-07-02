#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

// practice of concept virtual
int	main(void) {
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl; // dog
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound(); // dog
	meta->makeSound();

	delete meta;
	delete i;
	delete j;

	std::cout << "\n" << "==WrongExample==" << std::endl;
	const WrongAnimal* b = new WrongCat();

	std::cout << b->getType() << " " << std::endl;
	b->makeSound();

	delete b;
}
