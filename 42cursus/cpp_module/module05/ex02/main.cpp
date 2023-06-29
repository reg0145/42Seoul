#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "# [Ok]" << std::endl;
	{
		try {
			Bureaucrat master("master", 1);
			ShrubberyCreationForm shrubberyForm("shrubbery");
			RobotomyRequestForm robotomyForm("robotomy");
			PresidentialPardonForm pardonForm("pardonForm");

			std::cout << "/* shrubbery */" << std::endl;
			master.signForm(shrubberyForm);
			master.executeForm(shrubberyForm);

			std::cout << "\n/* robot */" << std::endl;
			master.signForm(robotomyForm);
			master.executeForm(robotomyForm);
			master.executeForm(robotomyForm);
			master.executeForm(robotomyForm);
			master.executeForm(robotomyForm);

			std::cout << "\n/* pardonForm */" << std::endl;
			master.signForm(pardonForm);
			master.executeForm(pardonForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
	std::cout << "\n" << "# [Exception] - grade is too low" << std::endl;
	{
		try {
			Bureaucrat donghyuk("donghyuk", 150);
			ShrubberyCreationForm shrubberyForm("shrubbery");
			donghyuk.signForm(shrubberyForm);
			//donghyuk.executeForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n" << "# [Exception] - not signed" << std::endl;
	{
		try {
			Bureaucrat donghyuk("donghyuk", 150);
			ShrubberyCreationForm shrubberyForm("shrubbery");
			//donghyuk.signForm(shrubberyForm);
			donghyuk.executeForm(shrubberyForm);
		} catch (std::exception &e) {
			std::cout << e.what() << std::endl;
		}
	}
}