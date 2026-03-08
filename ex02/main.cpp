#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


#include <ctime>
#include <cstdlib>

int main() {
	//Seed the random number generator for current time
	std::srand(std::time(0));

	//Create Bureaucrats
	Bureaucrat boss("The Boss", 1);
	Bureaucrat assistant("Assistant", 50);
	Bureaucrat intern("Junior", 150);

	std::cout << "--- Initial State ---" << std::endl;
	std::cout << boss << assistant << intern << std::endl;
	//tests

	// --- TEST 1: ShrubberyCreationForm ---
	std::cout << "--- TEST 1: ShrubberyCreationForm (Sign: 145, Exec: 137)" << std::endl;
	{
		ShrubberyCreationForm shrub("Adam");
		std::cout << shrub << std::endl;

		std::cout << "- Intern signing the form - " << std::endl;
		intern.signForm(shrub);
		std::cout << "- Assistant signing the form - " << std::endl;
		assistant.signForm(shrub);
		std::cout << "- Intern executing the form - " << std::endl;
		intern.executeForm(shrub);
		std::cout << "- Assistant executing the form - " << std::endl;
		assistant.executeForm(shrub);
		
	}

	// --- TEST 2: RobotomyRequestForm ---
	std::cout << "\n--- TEST 2: RobotomyRequestForm (Sign: 72, Exec: 45)" << std::endl;
	{
		RobotomyRequestForm robot("Bob");
		std::cout << robot << std::endl;

		std::cout << "- Intern signing the form - " << std::endl;
		intern.signForm(robot);
		std::cout << "- Assistant signing the form - " << std::endl;
		assistant.signForm(robot);
		std::cout << "- Assistant executing the form - " << std::endl;
		assistant.executeForm(robot);
		std::cout << "- Boss executing the form - " << std::endl;
		boss.executeForm(robot);
		
	}

	// --- TEST 3: PresidentialPardonForm ---
	std::cout << "\n--- TEST 3: PresidentialPardonForm (Sign: 25, Exec: 5)" << std::endl;
	{
		PresidentialPardonForm pardon("Dan");
		std::cout << pardon << std::endl;

		std::cout << "- Intern signing the form - " << std::endl;
		intern.signForm(pardon);
		std::cout << "- Assistant signing the form - " << std::endl;
		assistant.signForm(pardon);
		std::cout << "- Boss signing the form - " << std::endl;
		boss.signForm(pardon);
		std::cout << "- Assistant executing the form - " << std::endl;
		assistant.executeForm(pardon);
		std::cout << "- Boss executing the form - " << std::endl;
		boss.executeForm(pardon);
		
	}

	// --- TEST 4: Polymorphism & Memory Leak Test ---
	std::cout << "\n--- 4. Polymorphism & Memory Leak Test ---" << std::endl;
	{
		// Testing execution via base class pointer [cite: 193]
		AForm* form = new RobotomyRequestForm("Target_System");

		boss.signForm(*form);
		boss.executeForm(*form);

		// This requires the virtual destructor in AForm to avoid leaks [cite: 289]
		delete form; 
	}
	return(0);
}