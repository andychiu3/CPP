#include "Cat.hpp"
#include "Brain.hpp"
#include "Color.hpp"

Cat::Cat() 
	: Animal() {
		this->_brain = new Brain();
		std::cout << RED << "cat DFL constructor" << RESET << std::endl;
		_type = "Cat";
		std::cout << "origin _brain address: " << &_brain << std::endl;
}

Cat::Cat(const Cat& copy)
	: Animal(copy), _brain(new Brain(*copy._brain)) {
	std::cout << RED << "cat copy constructor" << RESET << std::endl;
	std::cout << RED << "new _brain address: " << &_brain << RESET << std::endl;
	std::cout << RED << "copy._brain address: " << &copy._brain << RESET << std::endl;
}

Cat&	Cat::operator=(const Cat& other) {
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*other._brain);
	}
	return *this;
}

Cat::~Cat() {
	std::cout << RED << "cat destructor" << RESET << std::endl;
	delete _brain;
}

void	Cat::makeSound() const {
	std::cout << RED << _type << ": Meow!" << RESET << std::endl;
}

Brain	*Cat::getBrain() const {
	return _brain;
}
