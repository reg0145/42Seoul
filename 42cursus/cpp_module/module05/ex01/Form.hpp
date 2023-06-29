#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string name, const int signGrade, const int executeGrade);
		Form(const Form &ref);
		~Form();
		Form &operator=(const Form &ref);

		std::string getName() const;
		int         getSignGrade() const;
		int         getExecuteGrade() const;
		bool        getSigned() const;
		void        beSigned(const Bureaucrat &ref);

		class GradeTooHighException : public std::exception{
			public:
				virtual const char * what() const throw();
		};

		class GradeTooLowException : public std::exception{
			public :
				virtual const char * what() const throw();
		};

	private:
		const std::string   mName;
		bool                mbSign;
		const int           mSignGrade;
		const int           mExecuteGrade;

		Form();
};

std::ostream &operator<<(std::ostream&, const Form&);

#endif