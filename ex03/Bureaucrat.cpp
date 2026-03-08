#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs) {
	if (this != &rhs) {
		// cannot copy _name because it's const. Copy only the grade.
		_grade = rhs._grade;
	}
	return *this;
}

std::string	Bureaucrat::getName() const {
	return _name;
}
int			Bureaucrat::getGrade() const {
	return _grade;
}

void		Bureaucrat::incrementGrade() {
	if (_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
	std::cout << "Grade incremented by 1 (--)" << std::endl;
}

void		Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
	std::cout << "Grade decremented by 1 (++)" << std::endl;
}

void		Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << "(Grade: " << _grade << ")" << GREEN << " signed " << RESET << form.getName() << std::endl;

	} catch (std::exception &e) {
		std::cout << _name << "(Grade: " << _grade << ")" << RED << " couldn't sign " << RESET << form.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(AForm const & form) const {
	try {
		form.execute(*this);
		std::cout << _name << "(Grade: " << _grade << ")" << GREEN << " executed " << RESET << form.getName() << std::endl;
	} catch (std::exception & e) {
		//If execution failed (not signed or grade too low), print the reason
		std::cout << _name << "(Grade: " << _grade << ")" << RED << " couldn't execute " << RESET << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& b) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
	return o;
}