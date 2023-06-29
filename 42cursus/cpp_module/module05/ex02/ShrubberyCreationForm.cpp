#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
: AForm("ShrubberyCreationForm", SIGN_GRADE, EXEC_GRADE), mTarget(target)
{
	std::cout << "ShrubberyCreationForm constructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ref)
: AForm(ref.getName(), SIGN_GRADE, EXEC_GRADE), mTarget(ref.mTarget)
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &ref)
{
	if (this != &ref)
	{
		AForm::operator=(ref);
		mTarget = ref.mTarget;
	}
	return *this;
}

std::string ShrubberyCreationForm::getTarget() const {
	return mTarget;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!getSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > getExecuteGrade())
		throw GradeTooLowException();

	std::string filename = mTarget + "_shrubbery";
	std::ofstream ofs(filename.c_str());
	if (ofs.is_open())
	{
		ofs << "              ,@@@@@@@," << std::endl;
		ofs << "      ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
		ofs << "   ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
		ofs << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
		ofs << "  %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
		ofs << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
		ofs << "  `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
		ofs << "      |o|        | |         | |" << std::endl;
		ofs << "      |.|        | |         | |" << std::endl;
		ofs << "  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;
		ofs.close();
	}
}
