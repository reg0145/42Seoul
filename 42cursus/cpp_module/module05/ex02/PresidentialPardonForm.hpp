#ifndef PRESIDENTIALPARDONFORM
#define PRESIDENTIALPARDONFORM

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &ref);
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &ref);

		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;

	private:
		enum
		{
			SIGN_GRADE = 25,
			EXEC_GRADE = 5
		};
		
		std::string         mTarget;

		PresidentialPardonForm();
};

#endif