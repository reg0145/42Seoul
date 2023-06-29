#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : mName(name), mGrade(grade)
{
	if (grade > LOW_GRADE)
		throw GradeTooLowException();
	if (grade < HIGH_GRADE)
		throw GradeTooHighException();
	std::cout << "Bureaucrat constructor" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &ref)
{
	*this = ref;
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return mName;
}

int Bureaucrat::getGrade() const
{
	return mGrade;
}

void Bureaucrat::incrementGrade()
{
	if ((mGrade - 1) < HIGH_GRADE)
		throw GradeTooHighException();
	mGrade--;
}

void Bureaucrat::decrementGrade()
{
	if ((mGrade + 1) > LOW_GRADE)
		throw GradeTooLowException();
	mGrade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "exception : Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "exception : Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref) {
	return os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
}
