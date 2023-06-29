#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE),
mTarget(target)
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &ref) :
AForm("PresidentialPardonForm", SIGN_GRADE, EXEC_GRADE),
mTarget(ref.mTarget)
{
	std::cout << "PresidentialPardonForm constructor" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &ref)
{
	if (this != &ref)
	{
		AForm::operator=(ref);
		mTarget = ref.mTarget;
	}
	return *this;
}

std::string PresidentialPardonForm::getTarget() const
{
	return mTarget;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();
	std::cout << mTarget << " has been pardoned by Zafod Beeblebrox" << std::endl;
}