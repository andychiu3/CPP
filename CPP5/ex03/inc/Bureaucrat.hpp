#pragma once

#include <iostream>
#include <exception>
#include "AForm.hpp"

typedef std::string str;
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150

class Bureaucrat {
	private:
		const str	_name;
		int	_grade;
		
	public:
		Bureaucrat();
		Bureaucrat(str name, int grade);
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat& operator=(const Bureaucrat& other);
		~Bureaucrat();

		// getter && setter
		const str& getName() const;
		int getGrade() const;
		void	setGrade(const int newGrade);

		// increment && decrement
		void	incrementGrade();
		void	decrementGrade();

		void	signForm(AForm& form);

		/* mandatory */
		void	executeForm(AForm const & form);

		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw();
		};
	} ;

std::ostream& operator<<(std::ostream& os, const Bureaucrat& Bureaucrat);
