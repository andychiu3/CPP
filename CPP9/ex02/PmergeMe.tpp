template<typename Container>
PmergeMe<Container>::PmergeMe() {}

template<typename Container>
template<typename Iter>
PmergeMe<Container>::PmergeMe(Iter begin, Iter end) : _data(begin, end) {}

template<typename Container>
PmergeMe<Container>::PmergeMe(const PmergeMe& copy) {
	_data = copy._data;
}

template<typename Container>
PmergeMe<Container>::~PmergeMe() {}

// operator
template<typename Container>
PmergeMe<Container>&	PmergeMe<Container>::operator=(const PmergeMe& other) {
	if (this != &other)
		_data = other._data;
	return *this;
}

// others
template<typename Container>
void	PmergeMe<Container>::sort() {
	clock_t	start = clock();
	fordJohnson();
	clock_t	end = clock();
	double	duration = static_cast<double>(end - start) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "Time to process a range of " << _data.size() << " elements "
			<< "with std::";

	if (typeid(Container) == typeid(std::vector<int>))
		std::cout << YELW << "vector" << RESET;
	else if (typeid(Container) == typeid(std::deque<int>))
		std::cout << YELW << "deque" << RESET;
	else if (typeid(Container) == typeid(std::list<int>))
		std::cout << YELW << "list" << RESET;
	else
		std::cout << "unknown Container";

	std::cout << " : " << duration << " us" << std::endl;
}

// template<typename Container>
// void	PmergeMe<Container>::fordJohnson() {
// 	if (_data.size() <= 1)
// 		return ;

// 	Container	main;
// 	Container	pend;
// 	typename Container::iterator	it = _data.begin();
// 	while (it != _data.end()) {
// 		typename Container::iterator	next = it;
// 		std::advance(next, 1);
// 		if (next != _data.end()) {
// 			int	bigger = std::max(*it, *next);
// 			int	smlr = std::min(*it, *next);
// 			main.push_back(bigger);
// 			pend.push_back(smlr);
// 			std::advance(it, 2);
// 		}
// 		else {
// 			main.push_back(*it);
// 			break ;
// 		}
// 	}
	
// 	PmergeMe<Container>	recursiveSort(main.begin(), main.end());
// 	recursiveSort.fordJohnson();
// 	main = recursiveSort._data;
// 	mergeInsertion(main, pend);
// 	_data = main;
// }

template<typename Container>
void	PmergeMe<Container>::selectionSort(std::vector<std::pair<int, int> >& pair,
	Container& main, Container& pend) {
	while (!pair.empty()) {
		typename std::vector<std::pair<int, int> >::iterator	minIt = pair.begin();
		for (typename std::vector<std::pair<int, int> >::iterator	it = pair.begin(); it != pair.end(); it++){
			if (it->first < minIt->first)
				minIt = it;
		}
		main.push_back(minIt->first);
		pend.push_back(minIt->second);

		pair.erase(minIt);
	}
}

template<typename Container>
void	PmergeMe<Container>::fordJohnson() {
	if (_data.size() <= 1)
		return ;

	std::vector<std::pair<int, int> >	pair;
	std::vector<int>	leftover;
	for (typename Container::iterator	it = _data.begin(); it != _data.end(); std::advance(it, 2)) {
		typename Container::iterator	next = it;
		std::advance(next, 1);
		if (next != _data.end()) {
			pair.push_back(std::make_pair(std::max(*it, *next), std::min(*it, *next)));
		} else {
			leftover.push_back(*it);
			break ;
		}
	}

	// std::sort(pair.begin(), pair.end());

	Container	main;
	Container	pend;
	selectionSort(pair, main, pend);

	// for (std::vector<std::pair<int, int> >::iterator	it = pair.begin(); it != pair.end(); it++) {
	// 	main.push_back(it->first);
	// 	pend.push_back(it->second);
	// }

	mergeInsertion(main, pend);
	
	if (leftover.size() != 0) {
		int	value = leftover.front();
		typename Container::iterator	pos = binarySearch(value, main.begin(), main.end());
		main.insert(pos, value);
	}
	_data = main;
}

// 0 1 1 3 5 11 21
// 0 1 2 3 4 5  6
template<typename Container>
size_t	PmergeMe<Container>::getJacobsthalIndex(size_t n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	size_t	prev = 1;
	size_t	prev2 = 0;
	for (size_t i = 2; i <= n; i++) {
		size_t	cur = prev + 2 * prev2; // Jacobsthal
		prev2 = prev;
		prev = cur;
	}
	return prev;
}

template<typename Container>
std::vector<size_t>	PmergeMe<Container>::getInsertionOrder(size_t n) {
	std::vector<size_t>	order;
	size_t	done = 0;

	if (n <= 0)
		return order;
	order.push_back(0);
	done = 1;

	for (size_t i = 3; getJacobsthalIndex(i) <= n; i++) {
		for (size_t tmp = getJacobsthalIndex(i); tmp > getJacobsthalIndex(i - 1); tmp--) {
			order.push_back(tmp - 1);
		}
		done = getJacobsthalIndex(i);
	}
	while (n > done) {
		order.push_back(--n);
	}
	return order;
}

template<typename Container>
typename Container::iterator	PmergeMe<Container>::binarySearch(int value, typename Container::iterator left, typename Container::iterator right) {
	while (std::distance(left, right) > 0) {
		typename Container::iterator	mid = left;
		std::advance(mid, std::distance(left, right) / 2);
		if (value > *mid)
			left = ++mid;
		else
			right = mid;
	}
	return left;
}

template<typename Container>
void	PmergeMe<Container>::mergeInsertion(Container& main, Container& pend) {
	std::vector<size_t>	insertionOrder = getInsertionOrder(pend.size());
	for (std::vector<size_t>::iterator	it = insertionOrder.begin();
				 it != insertionOrder.end(); it++) {
		size_t	index = *it;
		typename Container::iterator	pend_it = pend.begin();
		std::advance(pend_it, index);
		typename Container::value_type	value = *pend_it;
		if (index < pend.size()) {
			typename	Container::iterator	pos = binarySearch(value, main.begin(), main.end());
			main.insert(pos, value);
		}
	}
}

template<typename Container>
void	PmergeMe<Container>::print() const {
	for (size_t i = 0; i < _data.size(); i++) {
		std::cout << _data[i] << " ";
	}
	std::cout << std::endl;
}

template<typename Container>
bool	PmergeMe<Container>::checkForResult(const std::vector<int>& ref) {
	if (_data.size() != ref.size())
		return false;
	
	typename Container::const_iterator	it = _data.begin();
	std::vector<int>::const_iterator	ref_it = ref.begin();

	while (it != _data.end() && ref_it != ref.end()) {
		if (*it != *ref_it)
			return false;
		it++;
		ref_it++;
	}
	return true;
}
