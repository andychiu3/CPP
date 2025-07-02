#pragma once

#include <iostream>
#include <cmath>

class	Fixed {
	private:
		int					_fixedPointNumber;
		static const int	_fractionalBits = 8;
	
	public:
		Fixed();
		Fixed(const int);
		Fixed(const float);
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& a);
		~Fixed();
		
		Fixed operator+(const Fixed& a) const;
		Fixed operator-(const Fixed& a) const;
		Fixed operator*(const Fixed& a) const;
		Fixed operator/(const Fixed& a) const;

		bool	operator>(const Fixed& a) const;
		bool	operator<(const Fixed& a) const;
		bool	operator>=(const Fixed& a) const;
		bool	operator<=(const Fixed& a) const;
		bool	operator==(const Fixed& a) const;
		bool	operator!=(const Fixed& a) const;

		Fixed&	operator++();
		Fixed&	operator--();
		Fixed	operator++(int);
		Fixed	operator--(int);
		
		static Fixed&	min(Fixed& a, Fixed& b);
		static Fixed&	max(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);

		int		getRawBits(); // getter
		int		toInt() const;
		float	toFloat() const;
} ;

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed);
