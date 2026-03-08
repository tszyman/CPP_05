#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
		// Factory functions to create specific forms
		AForm* createShrubbery(std::string target);
		AForm* createRobotomy(std::string target);
		AForm* createPardon(std::string target);
	public:
		// Orthodox canonical form
		//Default consctuctor
		Intern();
		//Parametrized constructor
		//Copy constructor
		Intern(const Intern& src);
		//Assignment operator constructor
		Intern& operator=(const Intern& rhs);
		//Destructor
		~Intern();

		//Main function
		AForm* makeForm(std::string formName, std::string target);
};
#endif