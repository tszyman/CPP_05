#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
	private:
		const std::string	_name;
		int					_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		Form();					// Default Constructor
		Form(const std::string name, int _gradeToSign, int _gradetoExecute);	// Parametrized Constructor
		Form(const Form& src);	// Copy Constructor
		Form& operator=(const Form& rhs);					// Copy Assignment Operator
		~Form();			// Destructor

		//Getters & setters
		const 		std::string getName() const;
		int			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		// Member functions
		void		beSigned(const Bureaucrat& b);

		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Form grade is too high!";
				}
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Form grade is too low!";
				}
		};

};

// Ostream overload
std::ostream& operator<<(std::ostream& o, const Form& f);

#endif