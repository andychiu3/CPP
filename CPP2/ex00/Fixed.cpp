#include "Fixed.hpp"

const int Fixed::fractionalbits = 8;

Fixed::Fixed() : fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}


Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->fixedPointNumber = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return (fixedPointNumber);
}

void	Fixed::setRawBits(int const raw) {
	fixedPointNumber = raw;
}
