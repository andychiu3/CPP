#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm(std::string("ShrubberyCreationForm(") + target + ")", 145, 137)
	, _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
	: AForm(copy), _target(copy._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void	ShrubberyCreationForm::action() const {
		std::ofstream	outfile((_target + "_Shrubbery").c_str());

		if (!outfile.is_open()) {
			std::cerr << "Failed to open file" << std::endl;
			return ;
		}

		outfile << "    /\\    \n";
		outfile << "   /  \\   \n";
		outfile << "  /____\\  \n";
		outfile << "    ||    \n";
		outfile << "    ||    \n";

		outfile.close();
}
