#include "Fixed.hpp"

Fixed::Fixed() 
	: _fixedPointNumber(0) {
	// std::cout << "default constructor" << std::endl;
}

Fixed::Fixed(const int i) 
	: _fixedPointNumber(i << _fractionalBits){}

Fixed::Fixed(const float f) 
	: _fixedPointNumber(f *(1 << _fractionalBits)) {}

Fixed::Fixed(const Fixed& copy) {
	// std::cout << "copy constructor" << std::endl;
	*this = copy;
}

Fixed&	Fixed::operator=(const Fixed& a) {
	// std::cout << "copy assignment operator" << std::endl;
	if (this != &a)
		_fixedPointNumber = a._fixedPointNumber;
	return (*this);
}

Fixed	Fixed::operator+(const Fixed& a) const {
	return Fixed(this->toFloat() + a.toFloat());
}

Fixed	Fixed::operator-(const Fixed& a) const {
	return Fixed(this->toFloat() - a.toFloat());
}

Fixed	Fixed::operator*(const Fixed& a) const {
	return Fixed(this->toFloat() * a.toFloat());
}

Fixed	Fixed::operator/(const Fixed& a) const {
	return Fixed(this->toFloat() / a.toFloat());
}

bool	Fixed::operator>(const Fixed& a) const {
	return (this->_fixedPointNumber > a._fixedPointNumber);
}

bool	Fixed::operator<(const Fixed& a) const {
	return (this->_fixedPointNumber < a._fixedPointNumber);
}

bool	Fixed::operator>=(const Fixed& a) const {
	return (this->_fixedPointNumber >= a._fixedPointNumber);
}

bool	Fixed::operator<=(const Fixed& a) const {
	return (this->_fixedPointNumber <= a._fixedPointNumber);
}

bool	Fixed::operator==(const Fixed& a) const {
	return (this->_fixedPointNumber == a._fixedPointNumber);
}

bool	Fixed::operator!=(const Fixed& a) const {
	return (this->_fixedPointNumber != a._fixedPointNumber);
}

Fixed::~Fixed() {
	// std::cout << "destructor constructor" << std::endl;
}

Fixed&	Fixed::operator++() {
	_fixedPointNumber++;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed	tmp(*this);

	_fixedPointNumber++;
	return (tmp);
}

Fixed&	Fixed::operator--() {
	_fixedPointNumber--;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed	tmp(*this);

	_fixedPointNumber--;
	return (tmp);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	return b;
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	if (a < b)
		return (a);
	return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	if (a > b)
		return a;
	return b;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}

int	Fixed::getRawBits() {
	return _fixedPointNumber;
}

int	Fixed::toInt() const {
	return (_fixedPointNumber >> _fractionalBits);
}

float Fixed::toFloat() const{
	return (static_cast<float>(_fixedPointNumber / (1 << _fractionalBits)));
}
