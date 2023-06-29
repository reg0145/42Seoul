#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

#define LOW_GRADE 150
#define HIGH_GRADE 1

class Bureaucrat {
	public:
		Bureaucrat(const std::string name, const int grade);
		Bureaucrat(const Bureaucrat &ref);
		~Bureaucrat();

		std::string getName() const;
		int         getGrade() const;
		void        incrementGrade();
		void        decrementGrade();

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
		int                 mGrade;

		Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &ref);
};

std::ostream &operator<<(std::ostream&, const Bureaucrat&);


#endif