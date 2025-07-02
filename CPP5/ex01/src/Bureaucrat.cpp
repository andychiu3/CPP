#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat()
	: _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(str name, int grade)
	: _name(name) {
		setGrade(grade);
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

// mandatory
void	Bureaucrat::signForm(Form& form) {
	try {
		form.beSigned(*this);
		std::cout << "\033[32m" << _name << " signed Form: " << form.getName() << "\033[0m" << std::endl; 
	} catch (const Form::GradeTooLowException& e) {
		std::cout << "\033[31m" << _name << " couldn't sign Form: " << form.getName() 
		<< " because grade is too low" << "\033[0m" << std::endl;
	}
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
