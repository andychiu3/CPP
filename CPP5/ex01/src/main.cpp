#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	Bureaucrat	a;
	std::cout << a << std::endl;

	std::cout << "CREATING FORM:" << std::endl;
	Form	b;
	Form	*c = new Form("42", 42, 42);
	Form	d(*c);

	std::cout << b << std::endl;
	std::cout << *c << std::endl;
	std::cout << d << std::endl;
	try {
		Form	f("42", 0, 151);
	} catch (const std::exception& e) {
		std::cerr << "\033[31m" << e.what() << "\033[0m" << std::endl;
	}

	std::cout << "\nSIGNING FORM:" << std::endl;
	try {
		a.signForm(b);
		a.signForm(*c);
	} catch(const std::exception& e) {
		std::cerr << e.what() << '\n';
	}

	std::cout << b << std::endl;
	std::cout << *c << std::endl;
	
	delete c;
}
