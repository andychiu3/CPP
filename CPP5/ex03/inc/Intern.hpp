#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

typedef	std::string	str;

class Intern {
	private:

	public:
		/* Orthodox Canonical Form */
		Intern();
		Intern(const Intern& copy);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm*	makeForm(const str& name, const str& target) const;
		AForm*	createShrubberyCreationForm(const str& target) const;
		AForm*	createRobotomyRequestForm(const str& target) const;
		AForm*	createPresidentialPardonForm(const str& target) const;
}	;
