#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "Color.hpp"

int main() {
	std::cout << "============ PDF OBJS CREATED =============" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\n=========== PDF OBJS DESTROYED ===========" << std::endl;
	delete j;
	delete i;

	std::cout << "\n========== TESTS OBJS CREATED ===========" << std::endl;
	Animal *array[10];
	for (int i = 0; i < 5; i++)
		array[i] = new Dog();
	for (int i = 5; i < 10; i++)
		array[i] = new Cat();
	
	std::cout << "\n========== TESTS OBJS OUTPUT ==========" << std::endl;
	array[3]->makeSound();
	std::cout << array[3]->getType() 
			<< dynamic_cast<Dog *>(array[3])->getBrain()->getIdea(1) << std::endl;
	array[8]->makeSound();
	std::cout << array[8]->getType() 
			<< dynamic_cast<Cat *>(array[8])->getBrain()->getIdea(8) << std::endl;
	
	std::cout << "\n========== TESTS OBJS DESTROYED ==========" << std::endl;
	for (int i = 0; i < 10; i++)
		delete array[i];

	std::cout << "\n==== DEEP COPY OF COPY CONSTRUCTOR =====" << std::endl;
	Cat	a;
	Animal	*b = new Cat(a);

	std::cout << a.getType() << a.getBrain()->getIdea(4) << std::endl;
	std::cout << b->getType() << static_cast<Cat*>(b)->getBrain()->getIdea(4) << std::endl;

	delete b;

	std::cout << "\n======== DEEP COPY OF OPERATOR= ========" << std::endl;
	Dog	c;
	Dog	d;
	d = c;

	std::cout << c.getType() << c.getBrain()->getIdea(4) << std::endl;
	std::cout << d.getType() << d.getBrain()->getIdea(4) << std::endl;

	// Animal test;

	return 0;
}
