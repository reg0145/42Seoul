#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
: AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), mTarget(target)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm constructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &ref)
: AForm("RobotomyRequestForm", SIGN_GRADE, EXEC_GRADE), mTarget(ref.mTarget)
{
	srand(time(NULL));
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &ref)
{
	if (this != &ref)
	{
		AForm::operator=(ref);
		mTarget = ref.mTarget;
	}
	return *this;
}

std::string RobotomyRequestForm::getTarget() const
{
	return mTarget;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::cout << "Drilling noises..." << std::endl;

	if (rand() % 2)
		std::cout << mTarget << " has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomization failed" << std::endl;
}