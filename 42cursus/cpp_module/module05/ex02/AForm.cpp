#include "AForm.hpp"

AForm::AForm(const std::string &name, const int signGrade, const int executeGrade) :
mName(name), mSignGrade(signGrade), mExecuteGrade(executeGrade)
{
	if (signGrade < HIGH_GRADE || executeGrade < HIGH_GRADE)
		throw AForm::GradeTooHighException();
	if (signGrade > LOW_GRADE || executeGrade > LOW_GRADE)
		throw AForm::GradeTooLowException();
	std::cout << "AForm constructor" << std::endl;
}

AForm::AForm(const AForm &ref) :
mName(ref.mName), mbSign(ref.mbSign), mSignGrade(ref.mSignGrade), mExecuteGrade(ref.mExecuteGrade)
{
	std::cout << "AForm copy constructor" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor" << std::endl;
}

AForm &AForm::operator=(const AForm &ref)
{
	if (this != &ref)
		mbSign = ref.mbSign;
	return *this;
}

std::string AForm::getName() const
{
	return mName;
}

int AForm::getSignGrade() const
{
	return mSignGrade;
}

int AForm::getExecuteGrade() const
{
	return mExecuteGrade;
}

bool AForm::getSigned() const
{
	return mbSign;
}

void AForm::beSigned(const Bureaucrat &ref)
{
	if (mbSign == true)
		throw FormAlreadySignedException();
	if (mSignGrade < ref.getGrade())
		throw GradeTooLowException();
	mbSign = true;
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "exception : Grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw() {
	return "exception : Grade is too low!";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "exception : Form is not signed!";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
	return "exception : Form is already signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &ref) {
	return  os
			<< std::boolalpha
			<< ref.getName()
			<< " {"
			<< " signed : " << ref.getSigned()
			<< ", signGrade : " << ref.getSignGrade()
			<< ", executeGrade : " << ref.getExecuteGrade()
			<< "}";
}