#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm(std::string("RobotomyRequestForm(") + target + ")", 72, 45)
	, _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
	: AForm(copy), _target(copy._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void	RobotomyRequestForm::action() const {
		int	success = rand() % 2;
		if (success) {
			std::cout << "some drilling noises" << std::endl;
			std::cout << _target << 
				" has been robotomized successfully 50% of the time" << std::endl;
		} else
			std::cerr << "robotomy failed" << std::endl;
}
