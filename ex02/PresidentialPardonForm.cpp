#include "PresidentialPardonForm.hpp"

//Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("default_target") {}

//Parametrized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

//Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src), _target(src._target) {}

//Copy Assignment operator
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs) {
	if(this != &rhs){
		AForm::operator=(rhs);
	}
	return *this;
}

//Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

//Execute
void 	PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	// 1. Elegant check from base class
	this->checkExecutability(executor);

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std:: endl;
}