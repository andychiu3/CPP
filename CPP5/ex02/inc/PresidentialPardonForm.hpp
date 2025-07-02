#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string	_target;
		
	public:
		/* Orthodox Canonical Form */
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
		~PresidentialPardonForm();

		void	action() const;
}	;
