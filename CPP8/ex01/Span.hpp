#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <set>
#include <exception>
#include <algorithm>
#include <cstdlib>
#include <vector>

# define RED "\33[31m"
# define RESET "\33[0m"
# define GRN "\033[32m"

class Span {
	private:
		unsigned int	_max;
		std::multiset<int>	_numbers;

	public:
		// constructor
		Span();
		Span(unsigned int max);
		Span(const Span& copy);
		~Span();

		// operator
		Span&	operator=(const Span& other);

		// mandatory
		void	addNumber(int n);
		void	addNbrs(const std::vector<int>& vec);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

}	;

#endif
