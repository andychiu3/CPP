#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
	*this = copy;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
		*this = other;
	return *this;
}

Intern::~Intern() {}

AForm*	Intern::createShrubberyCreationForm(const str& target) const {
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::createRobotomyRequestForm(const str& target) const {
	return new RobotomyRequestForm(target);
}

AForm*	Intern::createPresidentialPardonForm(const str& target) const {
	return new PresidentialPardonForm(target);
}


AForm*	Intern::makeForm(const str& name, const str& target) const {
	const str avaiable_forms[3] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm"
		};

	AForm* (Intern::*forms[3])(const str&) const = {
		&Intern::createShrubberyCreationForm,
		&Intern::createRobotomyRequestForm,
		&Intern::createPresidentialPardonForm
	};

	/* lambda fptr */
	// AForm* (*forms[3])(const str& target) = {
	// 	[](const str& target) -> AForm* { return new ShrubberyCreationForm(target);},
	// 	[](const str& target) -> AForm* { return new RobotomyRequestForm(target);},
	// 	[](const str& target) -> AForm* { return new PresidentialPardonForm(target);}
	// };

	for (int i = 0; i < 3; i++) {
		if (name == avaiable_forms[i]) {
			std::cout << "\033[32m" << "Intern creates " << name << "\033[0m" << std::endl;
			return (this->*forms[i])(target);
		}
	}

	// throw	std::runtime_error("Form does not exist");
	std::cerr << "\033[31m" << "Form does not exist" << "\033[0m" << std::endl;
	return NULL;
}
