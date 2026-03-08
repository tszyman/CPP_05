#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
	private:
		const std::string	_name;
		int					_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExec;
	public:
		AForm();					// Default Constructor
		AForm(const std::string name, int _gradeToSign, int _gradetoExecute);	// Parametrized Constructor
		AForm(const AForm& src);	// Copy Constructor
		AForm& operator=(const AForm& rhs);					// Copy Assignment Operator
		virtual ~AForm();			// Destructor (with virtual modifier to know which instance to destroy)

		//Getters & setters
		std::string getName() const;
		int			getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExec() const;

		// Member functions
		void		beSigned(const Bureaucrat& b);

		// Pure virtual function to make the class Abstract
		virtual void execute(Bureaucrat const &executor) const = 0;

		// Validation logic
		void		checkExecutability(Bureaucrat const &executor) const;

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
		class NotSignedException : public std::exception {
			public:
				virtual const char * what() const throw() {
					return "Form not signed";
				}
		};
};

// Ostream overload
std::ostream& operator<<(std::ostream& o, const AForm& f);

#endif