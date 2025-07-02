#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base	*generate(void) {
	int	i = rand() % 3;
	switch (i) {
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void	identify(Base *ptr) {
	if (dynamic_cast<A*>(ptr))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(ptr))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(ptr))
		std::cout << "C" << std::endl;
}

void	identify(Base& ref) {
	try {
		A&	a = dynamic_cast<A&>(ref);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {}
	try {
		B&	b = dynamic_cast<B&>(ref);
		(void)b;
		std::cout << "B" << std::endl;
	} catch (std::exception &e) {}
	try {
		C&	c = dynamic_cast<C&>(ref);
		(void)c;
		std::cout << "C" << std::endl;
	} catch (...) {}
}

int	main() {
	srand(time(NULL));

	Base	*ptr = generate();
	Base&	ref = *ptr;
	std::cout << "---------- ptr ----------" << std::endl;
	identify(ptr);
	std::cout << "---------- ref ----------" << std::endl;
	identify(ref);
	delete ptr;
}
