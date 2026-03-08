#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

#include <ctime>
#include <cstdlib>

int main() {
	//Seed the random number generator for current time
	std::srand(std::time(0));

	//Create Bureaucrats
	Bureaucrat boss("The Boss", 1);
	Bureaucrat assistant("Assistant", 50);
	Bureaucrat junior("Junior", 150);
	Intern someRandomIntern;
	AForm* rrf;


	std::cout << "--- Initial State ---" << std::endl;
	std::cout << boss << assistant << junior << std::endl;
	//tests

	// TEST 1: Successful Robotomy Request ---
	std::cout << "--- TEST 1: Successful Robotomy Request ---" << std::endl;
	rrf = someRandomIntern.makeForm("robotomy request", "B");
	if (rrf) {
		std::cout << *rrf << std::endl;
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf; // Critical: Intern used 'new', we must delete
	}

	// Test 2: Successful Shrubbery Creation
	std::cout << "\n--- Test 2: Successful Shrubbery Creation ---" << std::endl;
	rrf = someRandomIntern.makeForm("shrubbery creation", "Backyard");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	// Test 3: Successful Presidential Pardon
	std::cout << "\n--- Test 3: Successful Presidential Pardon ---" << std::endl;
	rrf = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
	if (rrf)
	{
		boss.signForm(*rrf);
		boss.executeForm(*rrf);
		delete rrf;
	}

	// Test 4: Unknown Form Name
	std::cout << "\n--- Test 4: Unknown Form Name ---" << std::endl;
	rrf = someRandomIntern.makeForm("coffee request", "Intern");
	if (rrf)
		delete rrf;
	else
		std::cout << "Correct(error expected): rrf is NULL because the form name was invalid." << std::endl;

	return(0);
}