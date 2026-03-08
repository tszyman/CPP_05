#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <iostream>

class PresidentialPardonForm : public AForm {
	private:
		const std::string _target;

	public:
		//Default constructor	
		PresidentialPardonForm();
		
		//Parametrized constructor
		PresidentialPardonForm(const std::string _target);
		
		//Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& src);

		//Copy Assignment operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		//Destructor
		virtual ~PresidentialPardonForm();

		//Executor
		void	execute(Bureaucrat const & executor) const;
};

#endif