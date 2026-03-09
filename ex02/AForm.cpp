#include "AForm.hpp"
#include "Bureaucrat.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

// Default Constructor
AForm::AForm() : _name("Default Form"), _isSigned(false), _gradeToSign(150), _gradeToExec(150) {}

//Parametrized Constructor
AForm::AForm(const std::string name, int gradeToSign, int gradeToExec) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

// Copy assignment oparator
AForm& AForm::operator=(const AForm& rhs) {
	if (this != &rhs) {
		_isSigned = rhs._isSigned; // Only _isSigned is non-const
	}
	return *this;
}

// Destructor
AForm::~AForm() {}

// Getters
const std::string AForm::getName() const {
	return _name;
}

int			AForm::getIsSigned() const {
	return _isSigned;
}

int			AForm::getGradeToSign() const {
	return _gradeToSign;
}

int			AForm::getGradeToExec() const {
	return _gradeToExec;
}

// Member functions
void		AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= _gradeToSign) {
		_isSigned = true;
	}
	else{
		throw AForm::GradeTooLowException();
	}
}

// Validation logic
void AForm::checkExecutability(Bureaucrat const &executor) const {
	// Rule 1: The form must be signed
	if (!this->getIsSigned())
	{
		throw AForm::NotSignedException();
	}
	// Rule 2: The bureaucrat's grade must be high enough
	if (executor.getGrade() > this->getGradeToExec())
	{
		throw AForm::GradeTooLowException();
	}
}

// Ostream overload
std::ostream& operator<<(std::ostream& o, const AForm& f) {
	o << "Form " << f.getName() << " Status: "; 
	if (f.getIsSigned()){
		o << GREEN << "signed " << RESET;
	} else{
		o << RED << "unsigned " << RESET;
	}
	o << "Grade to Sign: " << f.getGradeToSign() << ", Grade To Exec: " << f.getGradeToExec() << ")";
	return o;
}
