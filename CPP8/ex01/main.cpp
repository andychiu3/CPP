#include "Span.hpp"
int	subjectTest() {
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	return 0;
}

int	main() {
	srand(time(NULL));

	std::cout << "---------- subject test ----------" << std::endl;

	subjectTest();
	std::cout << "---------- span with 10000 random numbers ----------" << std::endl;
	Span	nbrs(10005);
	std::vector<int>	tmp;
	for (size_t i = 0; i < 10000; i++)
		tmp.push_back(rand());
	try {
		nbrs.addNbrs(tmp);
		std::cout << "shortest span:\n" << nbrs.shortestSpan() << std::endl;
		std::cout << "\nlongest span:\n" << nbrs.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	std::cout << "---------- span with no room ----------" << std::endl;
	Span	err;
	try {
		err.addNumber(rand());
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << "---------- span less than 2 ----------" << std::endl;
	Span	aNbr(3);
	try {
		aNbr.addNumber(rand());
		std::cout << "shortest span:\n" << aNbr.shortestSpan() << std::endl;
		std::cout << "\nlongest span:\n" << aNbr.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}
