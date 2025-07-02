// #ifndef MUTANTSTACK_TPP
// # define MUTANTSTACK_TPP

// #include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() {}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container>& copy) 
	: std::stack<T, Container>(copy) {}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack() {}

// operator
template<typename T, typename Container>
MutantStack<T, Container>&	MutantStack<T, Container>::operator=(const MutantStack<T, Container>& other) {
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return *this;
}

// mandatory
template<typename T, typename Container>
typename	Container::iterator	MutantStack<T, Container>::begin() {
	return this->c.begin();
}

template<typename T, typename Container>
typename	Container::iterator	MutantStack<T, Container>::end() {
	return this->c.end();
}

// #endif