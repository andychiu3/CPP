#include "Brain.hpp"

unsigned int	Brain::_id = 12345;

Brain::Brain() {
	std::cout << "brain created" << std::endl;
	for (int i = 0; i < 100; i++)
		_idea[i] =  "Idea: " + genRanStr(10);
}

Brain::Brain(const Brain& copy) {
	std::cout << "brain copying" << std::endl;
	for (int i = 0; i < 100; i++)
		_idea[i] = copy._idea[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "same brain happens" << std::endl;
	if (this != &other)
		for (int i = 0; i < 100; i++)
			_idea[i] = other._idea[i];
	return *this;
}

Brain::~Brain() {
	std::cout << "brainless" << std::endl;
}

str	Brain::getIdea(unsigned int i) const {
	if (i >= 100) {
		std::cout << " ran out of ideas" << std::endl;
		return "";
	}
	return _idea[i];
}

unsigned int	Brain::genRanNbr() {
	_id = (_id * MULTIPLIER + INCREMENT) & MODULO_MASK;
	return _id;
}

str	Brain::genRanStr(int length) {
	const str	characters = "abcdefghijklmnopqrstuvwxyz0123456789";
	str	r;

	for (int i = 0; i < length; ++i) {
		unsigned int ranNbr = genRanNbr();
		char	ranChar = characters[ranNbr % characters.size()];
		r += ranChar;
	}
	return r;
}
