#include "WrongCat.hpp"

WrongCat::WrongCat() 
	: WrongAnimal() {
		std::cout << "WrongCat DFL constructor" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& copy)
	: WrongAnimal(copy) {

}

WrongCat&	WrongCat::operator=(const WrongCat& other) {
	if (this != &other) {
		WrongAnimal::operator=(other);
	}
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor" << std::endl;
}

void	WrongCat::makeSound() const {
	std::cout << _type << ": Meow!" << std::endl;
}
