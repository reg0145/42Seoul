#include "Intern.hpp"

int main(void)
{
	std::cout << "# [Ok]" << std::endl;
	{
		AForm *form;
		try 
		{
			Intern intern;
			form = intern.makeForm("shrubbery creation", "shrubbery");
			
			Bureaucrat master("donghyuk", 1);
			master.signForm(*form);
			std::cout << *form << std::endl;
			master.executeForm(*form);
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			delete form;
		}
	}

	std::cout << "\n" << "# [Exception] - MakeForm  nothing" << std::endl;
	{
		AForm *form;
		try {
			Intern intern;
			form = intern.makeForm("Nothing", "shrubbery");
			delete form;
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
			delete form;
		}
	}
}