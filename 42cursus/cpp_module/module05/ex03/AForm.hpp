#ifndef FORM
#define FORM

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string &name, const int signGrade, const int executeGrade);
		AForm(const AForm &ref);
		virtual ~AForm();
		AForm &operator=(const AForm &ref);

		virtual void    execute(Bureaucrat const &executor) const = 0;
		std::string     getName() const;
		bool            getSigned() const;
		std::string     getTarget() const;
		int             getSignGrade() const;
		int             getExecuteGrade() const;
		void            beSigned(const Bureaucrat &ref);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				virtual const char * what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormAlreadySignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		const std::string   mName;
		bool                mbSign;
		const int           mSignGrade;
		const int           mExecuteGrade;

		AForm();
};

std::ostream &operator<<(std::ostream&, const AForm&);

#endif