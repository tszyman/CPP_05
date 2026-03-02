#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Form;
class Bureaucrat {
	public:
		// Orthodox Canonical Form
		Bureaucrat();									// Default constructor
		Bureaucrat(const std::string name, int grade);	// Parametrized constructor
		Bureaucrat(const Bureaucrat& src);				// Copy constructor
		Bureaucrat& operator=(const Bureaucrat& rhs);	// Copy assignment operator
		~Bureaucrat();									// Destructor
		
		// Getters
		std::string	getName() const;
		int			getGrade() const;

		// Methods
		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form& form);
	
		// Excepstions
		class GradeTooHighException : public std::exception {
			public:
			virtual const char* what() const throw() {
				return "Grade is too high! (Max Grade = 1)";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
			virtual const char * what() const throw() {
				return "Grade is too low! (Min Grade = 150)";
			}
		};

	private:
	const std::string 	_name; // Constant name
	int					_grade; // Range 1 to 150
};

// Instertion operator overload
std::ostream& operator<<(std::ostream& o, const Bureaucrat& b);

#endif