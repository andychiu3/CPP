#include "Form.hpp"
#include "Bureaucrat.hpp"

/* constructor */
Form::Form()
	: _name("default"), _signed(false), _signedGrade(150), _executeGrade(150) {}

Form::Form(str name, int sGrade, int eGrade)
	: _name(name), _signed(false), _signedGrade(sGrade), _executeGrade(eGrade) {
		if (sGrade < 1 || eGrade < 1)
			throw GradeTooHighException();
		if (sGrade > 150 || eGrade > 150)
			throw GradeTooLowException();
	}

Form::Form(const Form& copy)
	: _name(copy._name), _signed(copy._signed), 
	_signedGrade(copy._signedGrade), _executeGrade(copy._executeGrade) {}

Form&	Form::operator=(const Form& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

Form::~Form() {}

/* getter setter*/
const str&	Form::getName() const {
	return _name;
}

bool	Form::isSigned() const {
	return _signed;
}

const int&	Form::gradeToSign() const {
	return _signedGrade;
}

const int&	Form::gradeToExec() const {
	return _executeGrade;
}

/* others */
void	Form::beSigned(const Bureaucrat& a) {
		if (a.getGrade() > _signedGrade)
			throw Form::GradeTooLowException();
		_signed = true;
}

const char*	Form::GradeTooHighException::what() const throw() {
	return "Form grade is too high";
}

const char*	Form::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& os, const Form& form) {
	return os << std::setw(15) << "Form: " << form.getName() << "\n"
			<< std::setw(15) << "singed: " << (form.isSigned() ? "Yes" : "No") << "\n"
			<< std::setw(15) << "grade2Sign: " << form.gradeToSign() << "\n"
			<< std::setw(15) << "grade2Exec: " << form.gradeToExec() << std::endl;
}
