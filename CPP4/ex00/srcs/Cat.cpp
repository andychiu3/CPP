#include "Cat.hpp"

Cat::Cat() 
	: Animal() {
		std::cout << "cat DFL constructor" << std::endl;
	_type = "Cat";
}

Cat::Cat(const Cat& copy)
	: Animal(copy) {

}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << "cat destructor" << std::endl;
}

void	Cat::makeSound() const {
	std::cout << _type << ": Meow!" << std::endl;
}
