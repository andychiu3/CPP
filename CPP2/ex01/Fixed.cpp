#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointNumber(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int i) : _fixedPointNumber(i << _fractionalBits) {
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fpn) : _fixedPointNumber(roundf(fpn * (1 << _fractionalBits))) {
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment constructor called" << std::endl;
	if (this != &other)
		this->_fixedPointNumber = other.getRawBits();
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const{
	return (this->_fixedPointNumber);
}

void	Fixed::setRawBits(int const raw){
	this->_fixedPointNumber = raw;
}

float	Fixed::toFloat(void) const {
	return static_cast<float>(this->_fixedPointNumber) / (1 << this->_fractionalBits);
}

int	Fixed::toInt(void) const {
	return this->_fixedPointNumber >> this->_fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& f){
	os << f.toFloat();
	return os;
}
