#include "Dog.hpp"
#include "Brain.hpp"
#include "Color.hpp"

Dog::Dog() : Animal() {
	this->_brain = new Brain();
	std::cout << GREEN << "dog default constructor called" << RESET << std::endl;
	_type = "Dog";
}

Dog::Dog(const Dog& copy) 
	: Animal(copy), _brain(new Brain(*copy._brain)) {
		std::cout << GREEN << "dog copy constructor called" << RESET << std::endl;
}

Dog&	Dog::operator=(const Dog& other) {
	if (this != &other) {
		Animal::operator=(other);
		std::cout << GREEN << "old _brain address: " << &_brain << RESET << std::endl;
		delete _brain;
		_brain = new Brain(*other._brain);
		std::cout << GREEN << "new _brain address: " << &_brain << RESET << std::endl;
		std::cout << GREEN << "other._brain address: " << &other._brain << RESET << std::endl;
	}
	return (*this);
}

Dog::~Dog() {
	std::cout << GREEN << "dog destructor called" << RESET << std::endl;
	delete _brain;
}

void	Dog::makeSound() const{
	std::cout << GREEN << _type << ": woof!" << RESET << std::endl;
}

Brain	*Dog::getBrain() const {
	if (!_brain)
		return nullptr;
	return _brain;
}
