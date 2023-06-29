#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern contructor" << std::endl;
}

Intern::Intern(const Intern &ref)
{
	*this = ref;
	std::cout << "Intern copy constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

Intern &Intern::operator=(const Intern &ref)
{
	if (this != &ref)
		;
	return *this;
}


AForm *Intern::makeForm(std::string formName, std::string target)
{
	const std::string formNames[] = {"robotomy request","presidential pardon", "shrubbery creation"};

	int idx  = -1;
	int size = sizeof(formNames)/sizeof(std::string);
	
	while (++idx < size && formNames[idx].compare(formName))
		;

	AForm *form;
	switch (idx)
	{
		case 0:
			form = new RobotomyRequestForm(target);
			break;
		case 1:
			form = new PresidentialPardonForm(target);
			break;
		case 2:
			form = new ShrubberyCreationForm(target);
			break;
		default:
			throw FormNotFoundException();
	}

	std::cout << "Intern creates " << *form << std::endl;
	return form;
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return "exception : Form not found";
}