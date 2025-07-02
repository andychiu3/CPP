#include "PmergeMe.hpp"

bool	isNbr(std::string str) {
	if (str.empty())
		return false;

	size_t	i = 0;
	if (str[0] == '+')
		i++;
	if (i == str.length())
		return false;
	
	for (; i < str.length(); i++) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}


template<typename Container>
Container	parseInput(int ac, char **av) {
	Container	result;
	for (int i = 1; i < ac; i++) {
		if (!isNbr((std::string(av[i]))))
			throw std::runtime_error("Error: takes positive integer only");
		
		errno = 0;
		char	*endptr;
		long	n = std::strtol(av[i], &endptr, 10);
		if (errno == ERANGE || n > INT_MAX || n < INT_MIN)
			throw std::runtime_error("Error: number out of range");
		result.push_back(static_cast<typename Container::value_type>(n));
	}
	return result;
}

/*
	ex00: btc: map
	ex01: RPN: stack
	ex02: Pmerge: vector, deque and maybe list
*/
int	main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe <positive int...>";
		return 1;
	} 
	try {
		std::vector<int>	vec = parseInput<std::vector<int> >(ac, av);
		std::deque<int>	deq = parseInput<std::deque<int> >(ac, av);
		std::list<int>	lst = parseInput<std::list<int> >(ac, av);
		std::vector<int>	vecCopy = vec;

		std::cout << std::setw(10) << "Before: ";
		for (int i = 1; i < ac; i++)
			std::cout << av[i] << " ";
		std::cout << std::endl;

		// duration of std::sort -> comparing purpose
		clock_t	start = clock();
		std::sort(vecCopy.begin(), vecCopy.end());
		clock_t	end = clock();
		double	duration = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;

		// output of std::sort -> result checking
		std::cout << std::setw(10) << "After: ";
		for (size_t i = 0; i < vecCopy.size(); i++) {
			std::cout << vecCopy[i] << " ";
		}
		std::cout << std::endl;
		std::cout << "Time to process a range of " << vecCopy.size() << " elements "
					<< "with std::sort : " << duration << " us\n" << std::endl;
		
		PmergeMe<std::vector<int> >	vecInt(vec.begin(), vec.end());
		vecInt.sort();
		std::cout << " -> Result check " 
				<< (vecInt.checkForResult(vecCopy) ? GRN "PASS" RESET : RED "FAIL" RESET) 
				<< std::endl;
		// std::cout << std::setw(10) << "After: ";
		// vecInt.print();

		PmergeMe<std::deque<int> >	deqInt(deq.begin(), deq.end());
		deqInt.sort();
		std::cout << " -> Result check " 
				<< (deqInt.checkForResult(vecCopy) ? GRN "PASS" RESET : RED "FAIL" RESET) 
				<< std::endl;
		// std::cout << std::setw(10) << "After: ";
		// deqInt.print();

		PmergeMe<std::list<int> >	lstInt(lst.begin(), lst.end());
		lstInt.sort();
		std::cout << " -> Result check " 
				<< (lstInt.checkForResult(vecCopy) ? GRN "PASS" RESET : RED "FAIL" RESET) 
				<< std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
