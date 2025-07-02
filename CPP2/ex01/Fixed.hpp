#ifndef FIXED_HPP
# define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed {
	private:
		int			_fixedPointNumber;
		static const int	_fractionalBits = 8;
		
	public:
		Fixed();
		Fixed(const int i);
		Fixed(const float fpn);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		~Fixed();

		int		getRawBits() const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;


} ;

std::ostream& operator<<(std::ostream& os, const Fixed& f);

#endif
