#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int	main(void) {
	Intern	intern;

	std::cout << "three forms creation tests:" << std::endl;
	AForm *scf = intern.makeForm("ShrubberyCreationForm", "A");
	if (scf)
		std::cout << *scf << std::endl;
	AForm *rrf = intern.makeForm("RobotomyRequestForm", "B");
	if (rrf)
		std::cout << *rrf << std::endl;
	AForm *ppf = intern.makeForm("PresidentialPardonForm", "C");
	if (ppf)
		std::cout << *ppf << std::endl;

	std::cout << "\nwrong derived class test:" << std::endl;
	RobotomyRequestForm*	cast = dynamic_cast<RobotomyRequestForm*>(ppf);
	if (cast) {
		std::cout << *cast << std::endl;
	} else {
		std::cerr << "\033[31m" << "WrongForm." << "\033[0m" << std::endl;
		std::cout << "Form: " << ppf->getName() << std::endl;
	}

	std::cout << "\ninvalid form:" << std::endl;
	AForm	*invalid = intern.makeForm("invalid", "D");
	if (invalid) {
		std::cout << *invalid << std::endl;
		delete invalid;
	}

	delete scf;
	delete rrf;
	delete ppf;

	return 0;
}
