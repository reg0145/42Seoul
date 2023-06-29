#include "Form.hpp"

int main(void)
{
	std::cout << "# [Ok]" << std::endl;
	{
		try
		{
			Bureaucrat donghyuk("donghyuk", 80);
			std::cout << donghyuk << std::endl;

			Form form("form", 80, 120);
			donghyuk.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n" << "# [Exception]\n# form.signGrade too high" << std::endl;
	{
		try
		{
			Form form("form", -1, 120);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n" << "# [Exception]\n# form.signGrade too low" << std::endl;
	{
		try
		{
			Form form("form", 160, 120);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n" << "# [Exception]\n# donghyuk.grade too low" << std::endl;
	{
		try
		{
			Bureaucrat donghyuk("donghyuk", 85);
			std::cout << donghyuk << std::endl;

			Form form("form", 80, 120);
			donghyuk.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}