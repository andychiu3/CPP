#include "Animal.hpp"

Animal::Animal() 
	: _type("Animal") {
	std::cout << "animal DFL constructor" << std::endl;
}

Animal::Animal(const Animal& copy) 
	: _type(copy._type) {
}

Animal& Animal::operator=(const Animal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

Animal::~Animal() {
	std::cout << "animal destructor" << std::endl;
}

std::string	Animal::getType() const {
	return _type;
}

void	Animal::makeSound() const{
	// std::cout  << _type << ": ??" << std::endl;
}