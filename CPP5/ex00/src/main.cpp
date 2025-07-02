#include "Bureaucrat.hpp"

int	main() {
	Bureaucrat	a;
	Bureaucrat	*b = new Bureaucrat("Andy", 42);
	Bureaucrat	c(a);

	std::cout << "BEFORE: " << std::endl;
	std::cout << a << std::endl;
	std::cout << *b << std::endl;
	std::cout << c << std::endl;
	
	try {
		Bureaucrat	d("D", 0);
	} catch (const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\nPROMOTION AND DEMOTION: " << std::endl;
	try {
		b->incrementGrade();
		c.decrementGrade();
	} catch (const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << '\n';
	}

	std::cout << "\nAFTER: " << std::endl;
	std::cout << a << std::endl;
	std::cout << *b << std::endl;
	std::cout << c << std::endl;

	delete b;
}
