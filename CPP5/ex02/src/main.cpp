#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main(void) {
	Bureaucrat	a("A", 84);
	Bureaucrat	e("E", 42);
	Bureaucrat	f("F", 3);
	Bureaucrat	g;

	ShrubberyCreationForm	b("what");
	RobotomyRequestForm	c;
	PresidentialPardonForm d;
	// AForm	test;
	
	srand(time(NULL));

	std::cout << "before signing" << std::endl;
	a.executeForm(b);
	a.executeForm(c);
	a.executeForm(d);
	std::cout << "\nsigning ShrubberyCreationForm:" << std::endl;
	g.signForm(b);
	a.signForm(b);
	std::cout << "\nsigning RobotomyRequestForm:" << std::endl;
	a.signForm(c);
	e.signForm(c);
	std::cout << "\nsigning PresidentialPardonForm:" << std::endl;
	g.signForm(d);
	f.signForm(d);
	std::cout << "\nexecuting ShrubberyCreationForm:" << std::endl;
	g.executeForm(b);
	a.executeForm(b);
	std::cout << "\nexecuting RobotomyRequestForm:" << std::endl;
	a.executeForm(c);
	e.executeForm(c);
	std::cout << "\nexecuting PresidentialPardonForm:" << std::endl;
	a.executeForm(d);
	f.executeForm(d);
}
