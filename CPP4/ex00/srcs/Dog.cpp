#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy) 
	: Animal(copy) {

}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << "dog destructor called" << std::endl;
}

void	Dog::makeSound() const{
	std::cout  << _type << ": bark!" << std::endl;
}
