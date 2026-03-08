#include "RobotomyRequestForm.hpp"

//Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default_target") {}

//Parametrized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

//Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src), _target(src._target) {}

//Copy Assignment operator
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs) {
	if(this != &rhs){
		AForm::operator=(rhs);
	}
	return *this;
}

//Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

//Executor
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	// 1. Elegant check from base class
	this->checkExecutability(executor);

	// 2. Action
	std::cout << "* BZZZZZZZZZZZT DRILLING NOISES * " << std::endl;

	// Generate a number (0 or 1)
	if (std::rand() % 2 == 0) {
		std::cout << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "The robotomy on " << _target << " failed." << std::endl;
	}
}
