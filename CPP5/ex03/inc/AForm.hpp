#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>

typedef	std::string str;
class	Bureaucrat;

class AForm
{
	private:
		const str	_name;
		bool	_signed;
		const int	_signedGrade;
		const int	_executeGrade;

	public:
		AForm();
		AForm(str name, int sGrade, int eGrade);
		AForm(const AForm& copy);
		AForm& operator=(const AForm& other);
		virtual ~AForm() = 0;

		/* getter && setter */
		const str&	getName() const;
		bool	isSigned() const;
		const int&	gradeToSign() const;
		const int&	gradeToExec() const;

		/* mandatory */
		virtual void	execute(Bureaucrat const & executor) const;

		/* others */
		void	beSigned(const Bureaucrat& a);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
}	;

std::ostream&	operator<<(std::ostream& os, const AForm& form);
