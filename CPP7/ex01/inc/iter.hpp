#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# define GRN "\033[32m"
# define RESET "\033[0m"

template<typename T>
void	iter(T* addr, size_t len, void (*f)(T&)) {
	for (size_t i = 0; i < len; i++)
		f(addr[i]);
}

template<typename T>
void	prnt(T& whatever) {
	std::cout << whatever << ' ';
}

#endif
