#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <cstring>
#include <cfloat>
#include <cmath>

#define DBL_MIN_ 4.9406564584124654e-324

class ScalarConverter {
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		static	void	convert(const std::string& literal);
}	;
