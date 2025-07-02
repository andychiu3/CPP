#include "BitcoinExchange.hpp"

// DATE,btc
// parse
// date -> btc has to be float or integer
// A data base to store the part -> have a << to output?
int	main(int ac, char **av) {
	if (ac != 2) {
		std::cerr << RED << "Error: could not open file" << RESET << std::endl;
		return 1;
	}

	try {
		BitcoinExchange	DB;
		// std::cout << DB << std::endl;
		DB.calcExchangeValue(std::string(av[1]));
	} catch (const std::exception& e) {
		std::cerr << RED << "catch: " << e.what() << RESET << std::endl;
	}
}
