#include "MutantStack.hpp"

int	subject() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

int	stackToList() {
	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s;
	std::list<int>::iterator	anotherIt = mstack.begin();
	for (; anotherIt != mstack.end(); anotherIt++) {
		s.push(*it);
	}
	return 0;
}

int	main() {
	std::cout << "---------- subject test comparison ----------" << std::endl;
	std::cout << "using MutansStack" << std::endl;
	subject();
	std::cout << "using list" << std::endl;
	stackToList();
	
	std::cout << "---------- other test ----------" << std::endl;
	MutantStack<int>	ms;

	ms.push(3);
	ms.push(2);
	ms.push(1);

	std::cout << "using mutantStack iterator for the output" << std::endl;
	MutantStack<int>::iterator it = ms.begin();
	for (; it != ms.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "top before poping" << std::endl;
	std::cout << ms.top() << std::endl;
	ms.pop();
	std::cout << "top after poping" << std::endl;
	std::cout << ms.top() << std::endl;
}
