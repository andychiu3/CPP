#include "ScalarConverter.hpp"

int	main(int ac, char **av) {
	// ScalarConverter a;
	if (ac > 2)
		std::cerr << "./conveter <input>" << std::endl;
	if (ac == 2)
		ScalarConverter::convert(av[1]);

	std::cout << "\033[32m" << "0" << "\033[0m" << std::endl;
	ScalarConverter::convert("0");

	std::cout << "\033[32m" << "nan" << "\033[0m" << std::endl;
	ScalarConverter::convert("nan");

	std::cout << "\033[32m" << "42.0f" << "\033[0m" << std::endl;
	ScalarConverter::convert("42.0f");

	std::cout << "-------------------------" << std::endl;

	std::cout << "\033[32m" << "a" << "\033[0m" << std::endl;
	ScalarConverter::convert("a");

	std::cout << "\033[32m" << "31" << "\033[0m" << std::endl;
	ScalarConverter::convert("31");

	std::cout << "\033[32m" << "32" << "\033[0m" << std::endl;
	ScalarConverter::convert("32");

	std::cout << "\033[32m" << "126" << "\033[0m" << std::endl;
	ScalarConverter::convert("126");

	std::cout << "\033[32m" << "127" << "\033[0m" << std::endl;
	ScalarConverter::convert("127");

	std::cout << "\033[32m" << "+nanf" << "\033[0m" << std::endl;
	ScalarConverter::convert("+nanf");

	std::cout << "\033[32m" << "inf" << "\033[0m" << std::endl;
	ScalarConverter::convert("inf");

	std::cout << "\033[32m" << "-inff" << "\033[0m" << std::endl;
	ScalarConverter::convert("-inff");

	std::cout << "\033[32m" << "INT_MAX" << "\033[0m" << std::endl;
	ScalarConverter::convert("2147483647");

	std::cout << "\033[32m" << "< INT_MIN" << "\033[0m" << std::endl;
	ScalarConverter::convert("-2147483649");

	std::cout << "\033[32m" << "3.14" << "\033[0m" << std::endl;
	ScalarConverter::convert("3.14");

	std::cout << "\033[32m" << "01" << "\033[0m" << std::endl;
	ScalarConverter::convert("01");

	std::cout << "\033[32m" << "0.000" << "\033[0m" << std::endl;
	ScalarConverter::convert("0.000");

	std::cout << "\033[32m" << "FLT_MAX" << "\033[0m" << std::endl;
	ScalarConverter::convert("3.4e+38");
	
	std::cout << "\033[32m" << "FLT_MIN" << "\033[0m" << std::endl;
	ScalarConverter::convert("1.175494351e-38");

	std::cout << "\033[32m" << "> DBL_MAX" << "\033[0m" << std::endl;
	ScalarConverter::convert("	1.8e+308");

	std::cout << "\033[32m" << "DBL_MIN > x > 0 " << "\033[0m" << std::endl;
	ScalarConverter::convert("4.9406564584124654e-325");

	std::cout << "-------------------------" << std::endl;

	std::cout << "\033[31m" << "empty" << "\033[0m" << std::endl;
	ScalarConverter::convert("");

	std::cout << "\033[31m" << "--ab" << "\033[0m" << std::endl;
	ScalarConverter::convert("--ab");

	std::cout << "\033[31m" << "+-ab" << "\033[0m" << std::endl;
	ScalarConverter::convert("+-ab");

	std::cout << "\033[31m" << "0a" << "\033[0m" << std::endl;
	ScalarConverter::convert("0a");

	std::cout << "\033[31m" << "0x1.91p1" << "\033[0m" << std::endl;
	ScalarConverter::convert("0x1.91p1");
}
