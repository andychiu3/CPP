#include "iter.hpp"

void	adding(int& i) {
	i++;
}

void	toLower(char& c) {
	c = std::tolower(c);
}

void	toUpper(std::string& str) {
	for (size_t i = 0; i < str.length(); i++)
		str[i] = std::toupper(str[i]);
}

int	main() {
	std::cout << "----- integer array test -----" << std::endl;
	int	intArray[] = {1, 2 ,3, 4, 5};
	size_t	i_size = (sizeof(intArray) / sizeof(intArray[0]));
	std::cout << GRN << "before" << RESET << std::endl;
	iter(intArray, i_size, prnt);
	std::cout << std::endl;
	iter(intArray, i_size, adding);
	std::cout << GRN  << "after" << RESET << std::endl;
	iter(intArray, i_size, prnt);

	std::cout << "\n----- char array test -----" << std::endl;
	char	charArray[] = "HI THERE";
	size_t	charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << GRN << "before" << RESET << std::endl;
	iter(charArray, charSize, prnt);
	std::cout << std::endl;
	iter(charArray, charSize, toLower);
	std::cout << GRN  << "after" << RESET << std::endl;
	iter(charArray, charSize, prnt);

	std::cout << "\n----- string array test -----" << std::endl;
	std::string	strArray[] = {"hello", "world", "!"};
	size_t	strSize = sizeof(strArray) / sizeof(strArray[0]);

	std::cout << GRN << "before" << RESET << std::endl;
	iter(strArray, strSize, prnt);
	std::cout << std::endl;
	iter(strArray, strSize, toUpper);
	std::cout << GRN  << "after" << RESET << std::endl;
	iter(strArray, strSize, prnt);
}
