#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <iostream>
#include <cstdlib>

class RobotomyRequestForm : public AForm {
	private:
		const std::string _target;

	public:
		//Default constructor
		RobotomyRequestForm();

		//Parametrized constructor
		RobotomyRequestForm(const std::string _target);

		//Copy constructor
		RobotomyRequestForm(const RobotomyRequestForm& src);

		//Copy Assignment Operator
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		//Destructor
		virtual ~RobotomyRequestForm();

		//Executor
		void execute(Bureaucrat const & executor) const;
};

#endif