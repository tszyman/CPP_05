#include "Intern.hpp"

#define RESET	"\033[0m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"

//DefC
Intern::Intern() {}
//CopyC
Intern::Intern(const Intern& src) {(void) src;}
//AssOpC
Intern& Intern::operator=(const Intern& rhs) {(void) rhs; return *this;}
//Destr
Intern::~Intern() {};

//Factory implementations
AForm* Intern::createShrubbery(std::string t) {return new ShrubberyCreationForm(t);}
AForm* Intern::createShrubbery(std::string t) {return new ShrubberyCreationForm(t);}
AForm* Intern::createShrubbery(std::string t) {return new ShrubberyCreationForm(t);}

AForm* Intern::makeForm(std::string formName, std::string target) {
	// 1. Define the strings to match against
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	// 2. Define the array of pointers to member functions
	typedef AForm* (Intern::*MemFn)(std::string);
	MemFn functions[] = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};

	// 3. Loop to find a match (no if/else chains!)
	for (int i = 0; i < 3; i++) {
		if (formName == names[i]) {
			std::cout << "Intern"<< GREEN <<" creates "<< RESET << formName << std::endl;
			return (this->*functions[i])(target);
		}
	}

	// 4. Handle non-existent form names
	std::cout << "Error: Intern "<<RED<<" cannot create"<< RESET <<" form '" << formName << "' because it is unknown." << std::endl;
	return NULL;
}