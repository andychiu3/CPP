#pragma once

#include <iostream>
#include <string>
#include <iomanip>

typedef	std::string str;

class	Bureaucrat;

class Form
{
	private:
		const str	_name;
		bool	_signed;
		const int	_signedGrade;
		const int	_executeGrade;

	public:
		Form();
		Form(str name, int sGrade, int eGrade);
		Form(const Form& copy);
		Form& operator=(const Form& other);
		~Form();

		/* getter setter */
		const str&	getName() const;
		bool	isSigned() const;
		const int&	gradeToSign() const;
		const int&	gradeToExec() const;

		/* mandatory function */
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

std::ostream&	operator<<(std::ostream& os, const Form& form);
