#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "# [Ok]" << std::endl;
	{
		try
		{
			Bureaucrat donghyuk("donghyuk", 75);
			std::cout << donghyuk << std::endl;

			donghyuk.incrementGrade();
			std::cout << donghyuk.getGrade() << std::endl;
			donghyuk.decrementGrade();
			std::cout << donghyuk.getGrade() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n# [Exception] Grade is too high" << std::endl;
	{
		try
		{
			Bureaucrat high("too high", HIGH_GRADE);
			high.incrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat high("too high", HIGH_GRADE + 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "\n# [Exception] Grade is too low" << std::endl;
	{
		try
		{
			Bureaucrat low("too low", LOW_GRADE);
			low.decrementGrade();
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		try
		{
			Bureaucrat minus("too low", LOW_GRADE - 1);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}		
	}
}