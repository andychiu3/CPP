#include "RPN.hpp"

// constructor
RPN::RPN() {}

RPN::RPN(const RPN& copy) 
	: _stack(copy._stack) {}
		
RPN::~RPN() {}

// operator
RPN&	RPN::operator=(const RPN& other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

// others
bool	RPN::isNbr(const std::string& token) {
	char	*endptr;

	int	i = strtol(token.c_str(), &endptr, 10);
	if (*endptr || (i == 0 && token != "0"))
		return false;

	return true;
}

bool	RPN::performOp(const std::string& token, float b, float a) {
	if (token == "+")
		_stack.push(b + a);
	else if (token == "-")
		_stack.push(b - a);
	else if (token == "/") {
		if (a == 0) {
			std::cerr << "Error: division by zero" << std::endl;
			return false;
		}
		_stack.push(b / a);
	}
	else if (token == "*")
		_stack.push(b * a);
	return true;
}

int	RPN::calc(int ac, char **av) {
	if (ac != 2) {
		std::cerr << "./RPN <calculation element>";
		return 1;
	}

	std::stringstream	ss(av[1]);
	std::string	token;
	while (ss >> token) {
		if (token == "+" || token == "-" || token == "/" ||token == "*") {
			if (_stack.size() < 2) {
				std::cerr << "Error: not enough operands" << std::endl;
				return 1;
			}
			float	a = _stack.top();
			_stack.pop();
			float	b = _stack.top();
			_stack.pop();
			
			if (!performOp(token, b, a))
				return 1;
		}
		else if (isNbr(token))
			_stack.push(std::atoi(token.c_str()));
		else {
			std::cerr << "Error: RPN takes nbrs and +-/* only" << std::endl;
			return 1;
		}
	}
	if (_stack.size() == 1)
		std::cout << _stack.top() << std::endl;
	else {
		std::cerr << "Error: format" << std::endl;
		return 1;
	}
	return 0;
}
