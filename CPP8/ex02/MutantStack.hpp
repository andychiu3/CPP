#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <iostream>

template<typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	private:


	public:
		// constructor
		MutantStack();
		MutantStack(const MutantStack<T, Container>& copy);
		~MutantStack();

		// operator
		MutantStack<T, Container>&	operator=(const MutantStack<T, Container>& other);

		// mandatory
		typedef	typename	Container::iterator	iterator; // cannot compile without this being set;
		iterator	begin();
		iterator	end();
}	;

#include "./MutantStack.tpp"
#endif
