#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, const int grade) : mName(name), mGrade(grade)
{
	if (grade > LOW_GRADE)
		throw GradeTooHighException();
	if (grade < HIGH_GRADE)
		throw GradeTooLowException();
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
		throw GradeTooLowException();
	mGrade--;
}

void Bureaucrat::decrementGrade()
{
	if ((mGrade + 1) > LOW_GRADE)
		throw GradeTooHighException();
	mGrade++;
}

void Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << mName << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << mName << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << mName << " executed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << mName << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}

}
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "exception : Grade is too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "exception : Grade is too low!";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &ref)
{
	return os << ref.getName() << ", bureaucrat grade " << ref.getGrade();
}
