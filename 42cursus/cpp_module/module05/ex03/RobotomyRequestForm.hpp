#ifndef ROBOTOMYREQUESTFORM
#define ROBOTOMYREQUESTFORM

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {
	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &ref);
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &ref);

		std::string getTarget() const;
		virtual void execute(Bureaucrat const &executor) const;

	private :
		enum
		{
			SIGN_GRADE = 72,
			EXEC_GRADE = 45
		};

		std::string         mTarget;

		RobotomyRequestForm();
};

#endif