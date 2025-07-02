#ifndef RPN_H
# define RPN_H

#include <stack>
#include <iostream>
#include <sstream>
#include <cstdlib>

class RPN {
	private:
		std::stack<float>	_stack;

	public:
		// constructor
		RPN();
		RPN(const RPN& copy);
		~RPN();

		// operator
		RPN&	operator=(const RPN& other);

		int	calc(int ac, char **av);
		bool	isNbr(const std::string& token);
		bool	performOp(const std::string& token, float b, float a);
}	;

#endif
