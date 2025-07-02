#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <set>
# include <deque>

# define RED "\33[31m"
# define RESET "\33[0m"
# define GRN "\033[32m"

template <typename T>
typename	T::iterator easyfind(T& container, int i) {
	return std::find(container.begin(), container.end(), i);
}

#endif
