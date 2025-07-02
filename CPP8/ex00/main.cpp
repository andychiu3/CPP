#include "easyfind.hpp"

int	main(int ac, char **av) {
	
	if (ac != 2) {
		std::cout << RED << "format: ./easyfind <nbr>" << RESET << std::endl;
		return 1;
	}

	int	nbr = atoi(av[1]);
	if (nbr == 0) {
		std::cout << RED << "argv[1] only takes nbr and no 0" << RESET << std::endl;
		return 1;
	}
	
	std::cout << "----------- vector -----------" << std::endl;
	std::vector<int>	c_vec;
	c_vec.push_back(1);
	c_vec.insert(c_vec.begin(), 3);
	c_vec.insert(c_vec.begin() + 1, 5);
	c_vec.push_back(7);
	c_vec.push_back(9);


	std::vector<int>::iterator	a = c_vec.begin();
	for (; a != c_vec.end(); a++)
		std::cout << *a << std::endl;
	std::vector<int>::iterator	it = easyfind(c_vec, nbr);
	if (it != c_vec.end())
		std::cout << GRN  << *it << " got found in container_vector" << RESET << std::endl;
	else
		std::cout << RED <<  "not found" << RESET << std::endl;

	std::cout << "----------- set -----------" << std::endl;
	std::set<int>	container_set;
	container_set.insert(2);
	container_set.insert(5);
	container_set.insert(1);
	container_set.insert(11);

	std::set<int>::iterator	b = container_set.begin();
	for (; b != container_set.end(); b++)
		std::cout << *b << std::endl;
	std::set<int>::iterator anotherIT = easyfind(container_set, nbr);
	if (anotherIT != container_set.end())
		std::cout << GRN << *anotherIT << " got found in container_set" << RESET << std::endl;
	else
		std::cout << RED << "not found" << RESET << std::endl;

	std::cout << "----------- deque -----------" << std::endl;
	std::deque<int>	container_deque;
	container_deque.push_back(3);
	container_deque.push_front(5);
	container_deque.push_back(1);
	container_deque.pop_back();

	std::deque<int>::iterator	c = container_deque.begin();
	for (; c != container_deque.end(); c++)
		std::cout << *c << std::endl;
	std::deque<int>::iterator otherIT = easyfind(container_deque, nbr);
	if (otherIT != container_deque.end())
		std::cout << GRN << *otherIT << " got found in container_deque" << RESET << std::endl;
	else
		std::cout << RED << "not found" << RESET << std::endl;
}
