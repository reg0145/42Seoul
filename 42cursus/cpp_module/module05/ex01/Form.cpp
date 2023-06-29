#include "Form.hpp"

Form::Form(const std::string name, const int signGrade, const int executeGrade) :
mName(name), mSignGrade(signGrade), mExecuteGrade(executeGrade)
{
	if (signGrade < HIGH_GRADE  || executeGrade < HIGH_GRADE)
		throw Form::GradeTooHighException();
	if (signGrade > LOW_GRADE || executeGrade > LOW_GRADE)
		throw Form::GradeTooLowException();
	std::cout << "Form constructor" << std::endl;
}

Form::Form(const Form &ref) :
mName(ref.mName), mbSign(ref.mbSign), mSignGrade(ref.mSignGrade), mExecuteGrade(ref.mExecuteGrade)
{
	std::cout << "Form copy constructor" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor" << std::endl;
}

Form &Form::operator=(const Form &ref)
{
	if (this != &ref)
		mbSign = ref.mbSign;
	return *this;
}

std::string Form::getName() const
{
	return mName;
}

int Form::getSignGrade() const
{
	return mSignGrade;
}

int Form::getExecuteGrade() const
{
	return mExecuteGrade;
}

bool Form::getSigned() const
{
	return mbSign;
}

void Form::beSigned(const Bureaucrat &ref)
{
	if (mSignGrade < ref.getGrade())
		throw GradeTooLowException();
	mbSign = true;
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "exception : Grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw() {
	return "exception : Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Form &ref) {
	return  os
			<< std::boolalpha
			<< ref.getName()
			<< " {"
			<< " signed : " << ref.getSigned()
			<< ", signGrade : " << ref.getSignGrade()
			<< ", executeGrade : " << ref.getExecuteGrade()
			<< "}";
}