#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern &ref);
		~Intern();
		Intern &operator=(const Intern &ref);
		AForm *makeForm(std::string formName, std::string target);

	class FormNotFoundException : public std::exception {
		public:
			virtual const char *what() const throw();
	};
};

#endif