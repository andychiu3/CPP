#pragma once

#include <iostream>

class	Fixed {
	private:
		int					fixedPointNumber;
		static const int	fractionalbits;

	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed&	operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
} ;
