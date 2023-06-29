#ifndef SHRUBBERYCREATIONFORM
#define SHRUBBERYCREATIONFORM

#include "AForm.hpp"
#include "fstream"

class ShrubberyCreationForm : public AForm {
	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &ref);
		virtual ~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &ref);

		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;

	private:
		enum
		{
			SIGN_GRADE = 145,
			EXEC_GRADE = 137
		};
		
		std::string mTarget;

		ShrubberyCreationForm();
};

#endif