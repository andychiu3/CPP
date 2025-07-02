#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* constructor */
AForm::AForm()
	: _name("default"), _signed(false), _signedGrade(150), _executeGrade(150) {}

AForm::AForm(str name, int sGrade, int eGrade)
	: _name(name), _signed(false), _signedGrade(sGrade), _executeGrade(eGrade) {
		if (sGrade < 1 || eGrade < 1)
			throw GradeTooHighException();
		if (sGrade > 150 || eGrade > 150)
			throw GradeTooLowException();
	}

AForm::AForm(const AForm& copy)
	: _name(copy._name), _signed(copy._signed), 
	_signedGrade(copy._signedGrade), _executeGrade(copy._executeGrade) {}

AForm&	AForm::operator=(const AForm& other) {
	if (this != &other)
		_signed = other._signed;
	return *this;
}

AForm::~AForm() {}

/* getter setter*/
const str&	AForm::getName() const {
	return _name;
}

bool	AForm::isSigned() const {
	return _signed;
}

const int&	AForm::gradeToSign() const {
	return _signedGrade;
}

const int&	AForm::gradeToExec() const {
	return _executeGrade;
}

/* others */
void	AForm::beSigned(const Bureaucrat& a) {
		if (a.getGrade() > _signedGrade)
			throw AForm::GradeTooLowException();
		_signed = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	if (!_signed)
		throw std::runtime_error("Form is not signed");
	if (executor.getGrade() > _executeGrade)
		throw GradeTooLowException();
}

const char*	AForm::GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char*	AForm::GradeTooLowException::what() const throw() {
	return "Grade is too low";
}

std::ostream&	operator<<(std::ostream& os, const AForm& form) {
	return os << std::setw(15) << "Form: " << form.getName() << "\n"
			<< std::setw(15) << "singed: " << (form.isSigned() ? "Yes" : "No") << "\n"
			<< std::setw(15) << "grade2Sign: " << form.gradeToSign() << "\n"
			<< std::setw(15) << "grade2Exec: " << form.gradeToExec() << std::endl;
}
