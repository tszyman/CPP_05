#include "Form.hpp"
#include "Bureaucrat.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

// Default Constructor
Form::Form() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

//Parametrized Constructor
Form::Form(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
}

// Copy constructor
Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

// Copy assignment oparator
Form& Form::operator=(const Form& rhs) {
	if (this != &rhs) {
		_isSigned = rhs._isSigned; // Only _isSigned is non-const
	}
	return *this;
}

// Destructor
Form::~Form() {}

// Getters
std::string Form::getName() const {
	return _name;
}

int			Form::getIsSigned() const {
	return _isSigned;
}

int			Form::getGradeToSign() const {
	return _gradeToSign;
}

int			Form::getGradeToExec() const {
	return _gradeToExec;
}

// Member functions
void		Form::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _gradeToSign) {
		_isSigned = true;
	}
	else{
		throw Form::GradeTooLowException();
	}
}

// Ostream overload
std::ostream& operator<<(std::ostream& o, const Form& f) {
	o << "Form " << f.getName() << " Status: "; 
	if (f.getIsSigned()){
		o << GREEN << "signed " << RESET;
	} else{
		o << RED << "unsigned " << RESET;
	}
	o << "Grade to Sign: " << f.getGradeToSign() << ", Grade To Exec: " << f.getGradeToExec() << ")";
	return o;
}
