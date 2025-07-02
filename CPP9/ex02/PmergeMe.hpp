#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <ctime>
#include <cerrno>
#include <climits>
#include <iostream>
#include <cstdlib>
#include <exception>
#include <typeinfo>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>

#define YELW "\033[33m"
#define GRN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

template<typename Container>
class PmergeMe
{
	private:
		Container	_data;

	public:
		// constructor
		PmergeMe();
		template<typename Iter>
		PmergeMe(Iter begin, Iter end);
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();

		// operator
		PmergeMe&	operator=(const PmergeMe& other);

		void	sort();
		void	fordJohnson();
		void	selectionSort(std::vector<std::pair<int, int> >& pair, Container& main, Container& pend);
		size_t	getJacobsthalIndex(size_t n);
		std::vector<size_t>	getInsertionOrder(size_t n);
		typename Container::iterator	binarySearch(int value, typename Container::iterator left, typename Container::iterator right);
		void	mergeInsertion(Container& main, Container& pend);
		void	print() const;
		bool	checkForResult(const std::vector<int>& ref);
}	;

#include "PmergeMe.tpp"
#endif
