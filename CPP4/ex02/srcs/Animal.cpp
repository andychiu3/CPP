#include "Animal.hpp"
#include "Color.hpp"

Animal::Animal() 
	: _type("Animal") {
	std::cout << YELLOW << "animal DFL constructor" << RESET << std::endl;
}

Animal::Animal(const Animal& copy) 
	: _type(copy._type) {
	std::cout << YELLOW << "animal copy constructor" << RESET << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << YELLOW << "animal destructor" << RESET << std::endl;
}

std::string	Animal::getType() const {
	return _type;
}

// void	Animal::makeSound() const{
// 	std::cout << YELLOW << _type << " is making noise" << RESET << std::endl;
// }