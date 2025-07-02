#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) {
	(void)copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// nan, inf
static int	outIntRange(const std::string& str) {
	char	*endptr;
	if (str.find('e') != std::string::npos || str.find('E') != std::string::npos) {
		float	f = strtof(str.c_str(), &endptr);
		return f > static_cast<float>(INT_MAX) || f < static_cast<float>(INT_MIN);
	}

	errno = 0;
	long	l = strtol(str.c_str(), &endptr, 10);
	(void)l;
	return str == "nan" || str == "+nan" || str == "-nan"
		|| str == "nanf" || str == "+nanf" || str == "-nanf"
		|| str == "inf" || str == "+inf" || str == "-inf"
		|| str == "inff" || str == "+inff" || str == "-inff"
		|| errno == ERANGE || l > INT_MAX || l < INT_MIN;
}

static int	outFltRange(const std::string& str) {
	char	*endptr;
	errno = 0;
	double	d = strtod(str.c_str(), &endptr);
	if (str == "inf" || str == "+inf" || str == "-inf"
		|| str == "inff" || str == "+inff" || str == "-inff")
		return 0;
	return d > FLT_MAX || d < -FLT_MAX;
		// || (d < FLT_MIN && d > 0) || (d > -FLT_MIN && d < 0);
}

static int	outDblRange(const std::string& str) {
	char	*endptr;
	errno = 0;
	double	d = strtod(str.c_str(), &endptr);
	return errno == ERANGE && fabs(d) > 0;
}

static int	maybeHex(const std::string& str) {
	return str[0] == '0' && (str[1] == 'x' || str[1] == 'X') && str.length() > 2;
}

static int	isChar(const std::string& str) {
	return str.length() == 1 && !isdigit(str[0]);
}

// errno == ERANGE -> overflow or underflow
// *endptr == '\0' -> check nothing behind the nbr
// c++98 has strtol and strtod but no strtof
// strtof and strtod have diff logic sometimes
static int	isInt(const std::string& str) {
	if (str.empty())
		return 0;

	char	*endptr;
	errno = 0;
	long	l = strtol(str.c_str(), &endptr, 10);
	(void)l;
	// std::cout << "**********" << l << std::endl;
	return *endptr == '\0';
}

static int	isFloat(const std::string& str) {
	if (str.empty() || str == "f")
		return 0;
	
	char	*endptr;
	errno = 0;
	float	f = strtof(str.c_str(), &endptr);
	(void)f;
	return *endptr == 'f' && *(endptr + 1) == '\0';
}

static int	isDouble(const std::string& str) {
	if (str.empty())
		return 0;

	char	*endptr;
	errno = 0;
	double	d = strtod(str.c_str(), &endptr);
	(void)d;
	return *endptr == '\0';
}

template <typename T>
void	charRangeCase(T value) {
	int	i = static_cast<int>(value);

	if (isprint(static_cast<unsigned char>(value)))
		std::cout << std::setw(10) << "char: " << "'" << static_cast<char>(i) << "'" << std::endl;
	else if ((value >= 0 && value <= 32) || value == 127)
		std::cout << std::setw(10) << "char: " << "Non displayable" << std::endl;
	else
		std::cout << std::setw(10) << "char: " << "impossible" << std::endl;
}

void	printChar(char c) {
	std::cout << std::setw(10) << "char: " << c << std::endl;
	std::cout << std::setw(10) << "int: " << static_cast<int>(c) << std::endl;
	std::cout << std::setw(10) << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << std::setw(10) << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void	printInt(int i, const std::string& str) {
	charRangeCase(i);

	if (outIntRange(str))
		std::cout << std::setw(10) << "int: " << "impossible" << std::endl;
	else
		std::cout << std::setw(10) << "int: " << i << std::endl;

	std::cout << std::setw(10) << "float: " << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << std::setw(10) << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void	printFloat(float f, const std::string& str) {
	// char
	charRangeCase(f);

	// int
	if (outIntRange(str))
		std::cout << std::setw(10) << "int: " << "impossible" << std::endl;
	else
		std::cout << std::setw(10) << "int: " << static_cast<int>(f) << std::endl;

	// float and double
	int	i = static_cast<int>(f);
	if (outFltRange(str))
		std::cout << std::setw(10) << "float: " << f << "impossible" << std::endl;
	else if (f - i == 0) {
		std::cout << std::setw(10) << "float: " << f << ".0f" << std::endl;
		std::cout << std::setw(10) << "double: " << static_cast<double>(f) << ".0" << std::endl;
	} else {
		std::cout << std::setw(10) << "float: " << f << "f" << std::endl;
		std::cout << std::setw(10) << "double: " << static_cast<double>(f) << std::endl;
	}
}

void	printDouble(double d, const std::string& str) {
	// char
	charRangeCase(d);

	// int
	if (outIntRange(str))
		std::cout << std::setw(10) << "int: " << "impossible" << std::endl;
	else
		std::cout << std::setw(10) << "int: " << static_cast<int>(d) << std::endl;
	
	// float and double
	int	i = static_cast<int>(d);
	if (d - i == 0) {
		if (outFltRange(str))
			std::cout << std::setw(10) << "float: " << "impossible" << std::endl;
		else
			std::cout << std::setw(10) << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		if (outDblRange(str))
			std::cout << std::setw(10) << "double: " << "impossible" << std::endl;
		else
			std::cout << std::setw(10) << "double: " << d << ".0" << std::endl;
	} else {
		if (outFltRange(str))
			std::cout << std::setw(10) << "float: " << "impossible" << std::endl;
		else if ((d < FLT_MIN && d > 0) || (d > -FLT_MIN && d < 0))
			std::cout << std::setw(10) << "float: " << static_cast<float>(d) << ".0f" << std::endl;
		else
			std::cout << std::setw(10) << "float: " << static_cast<float>(d) << "f" << std::endl;
		if (outDblRange(str))
			std::cout << std::setw(10) << "double: " << "impossible" << std::endl;
		else
			std::cout << std::setw(10) << "double: " << d << std::endl;
	}
}

void	ScalarConverter::convert(const std::string& literal) {
	char	*endptr;
	if (maybeHex(literal)) {
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	
	if (isChar(literal)) {
		printChar(static_cast<char>(literal[0]));
	} else if (isInt(literal)) {
		printInt(atoi(literal.c_str()), literal);
	} else if (isFloat(literal)) {
		printFloat(atof(literal.c_str()), literal);
	} else if (isDouble(literal)) {
		printDouble(strtod(literal.c_str(), &endptr), literal);
	} else
		std::cout << "Invalid input" << std::endl;
}
