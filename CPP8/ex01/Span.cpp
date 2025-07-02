#include "Span.hpp"

Span::Span() 
	: _max(0) {}

Span::Span(unsigned int max)
	: _max(max) {}

Span::Span(const Span& copy) 
	: _max(copy._max), _numbers(copy._numbers) {}

Span::~Span() {
	_numbers.clear();
}

// operator
Span&	Span::operator=(const Span& other) {
	if (this != &other) {
		_max = other._max;
		_numbers = other._numbers;
	}
	return *this;
}

// mandatory
void	Span::addNumber(int n) {
	if (_numbers.size() >= _max)
		throw std::overflow_error("span overflow");
	_numbers.insert(n);
}

void	Span::addNbrs(const std::vector<int>& vec) {
	if (_numbers.size() + vec.size() >= _max)
		throw std::overflow_error("span would overflow");
	_numbers.insert(vec.begin(), vec.end());
}

unsigned int	Span::shortestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Needs 2 nbr");
	
	std::multiset<int>::iterator	a = _numbers.begin();
	std::multiset<int>::iterator	b = _numbers.begin();
	b++;

	unsigned int	s = *b - *a;
	for (; b != _numbers.end(); a++, b++) {
		unsigned int tmp = *b - *a;
		s = std::min(tmp, s);
	}
	return s;
}

unsigned int	Span::longestSpan() {
	if (_numbers.size() < 2)
		throw std::logic_error("Needs 2 nbr");
	return *std::max_element(_numbers.begin(), _numbers.end())
		- *std::min_element(_numbers.begin(), _numbers.end());
}
