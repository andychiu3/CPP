#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() 
	: _type("WrongAnimal") {
	std::cout << "WrongAnimal DFL constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy) 
	: _type(copy._type) {
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor" << std::endl;
}

std::string	WrongAnimal::getType() const {
	return _type;
}

void	WrongAnimal::makeSound() const{
	std::cout  << _type << " make noise" << std::endl;
}
