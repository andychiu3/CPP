#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(str name, int grade)
	: _name(name) {
		setGrade(grade); // to handle the range
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
	: _name(copy._name), _grade(copy._grade) {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

const str&	Bureaucrat::getName() const {
	return (_name);
}

int	Bureaucrat::getGrade() const {
	return (_grade);
}

void	Bureaucrat::setGrade(const int newGrade) {
	if (newGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (newGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	_grade = newGrade;
}

void	Bureaucrat::incrementGrade() {
	setGrade(_grade - 1);
}

void	Bureaucrat::decrementGrade() {
	setGrade(_grade + 1);
}

const char*	Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char*	Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat) {
	os << Bureaucrat.getName() << ", bureaucrat grade " << Bureaucrat.getGrade();
	return os;
}
