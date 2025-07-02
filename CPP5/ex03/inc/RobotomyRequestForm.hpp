#include "AForm.hpp"

class RobotomyRequestForm : public	AForm {
	private:
		std::string	_target;
		
	public:
		/* Orthodox Canonical Form */
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;
}	;

