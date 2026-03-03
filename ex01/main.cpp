#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main() {
	// Test 1: Valid construction and printing
	// Since exceptions are used: try - catch should be used
	try {
		std::cout << "// Test 1: Valid construction and printing" << std::endl;
		Bureaucrat b1("John", 2);
		std::cout << b1;
		b1.incrementGrade();
		std::cout << "After increment: " << b1;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//Test 2: Grade too high during construction
	std::cout << std::endl;
	try {
		std::cout << "//Test 2: Grade too high during construction" << std::endl;
		Bureaucrat b2("Tom", 0);
	} catch (std::exception &e) {
		std::cerr << "Caught expected error: " << e.what() << std::endl;
	}

	//Test 3: Grade too high during incrementation
	std::cout << std::endl;
	try {
		std::cout << "//Test 3: Grade too high during incrementation" << std::endl;
		Bureaucrat b3("Paul", 2);
		std::cout << b3;
		b3.incrementGrade();
		std::cout << "After increment: " << b3;
		b3.incrementGrade();
		std::cout << "After increment: " << b3;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//Test 4: Grade too low during incrementation
	std::cout << std::endl;
	try {
		std::cout << "//Test 4: Grade too low during incrementation" << std::endl;
		Bureaucrat b4("Adam", 148);
		b4.decrementGrade();
		std::cout << "After decrement: " << b4;
		b4.decrementGrade();
		std::cout << "After decrement: " << b4;
		b4.decrementGrade();
		std::cout << "After decrement: " << b4;
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	//Test 5: Attempt to create a Form with grade 0
	std::cout << std::endl;
	try {
		std::cout << "//Test 5: Attempt to create a Form with grade 0" << std::endl;
		Form f1("Topest Secret Form", 0, 50);
	} catch (std::exception &e) {
		std::cerr << "Caught expected error: " << e.what() << std::endl;
	}

	//Test 6: Attempt to create a Form with grade 151
	std::cout << std::endl;
	try {
		std::cout << "//Test 6: Attempt to create a Form with grade 151" << std::endl;
		Form f2("Garbage Form", 50, 151);
	} catch (std::exception &e) {
		std::cerr << "Caught expected error: " << e.what() << std::endl;
	}

	//Test 7: A Bureaucrat with grade 10 attempts to sign a Form requiring grade 50
	std::cout << std::endl;
	try {
		std::cout << "//Test 7: A Bureaucrat with grade 10 attempts to sign a Form requiring grade 50" << std::endl;
		Bureaucrat b5("Bob", 10);
		Form f3("Grade-50-Form", 50, 50);
		std::cout << b5;
		std::cout << f3 << std::endl;

		b5.signForm(f3); // Should be ok
		std::cout << f3 << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Unexpected error: " << e.what() << std::endl;
	}

	//Test 8: A Bureaucrat with grade 150 attempts to sign a Form requiring grade 1. (should trigger the catch block in signForm)
	std::cout << std::endl;
	try {
		std::cout << "//Test 8: A Bureaucrat with grade 150 attempts to sign a Form requiring grade 1. (should trigger the catch block in signForm)" << std::endl;
		Bureaucrat b6("Alan", 150);
		Form f4("Grade-1-Form", 1, 1);
		std::cout << b6;
		std::cout << f4 << std::endl;

		b6.signForm(f4);
		std::cout << f4 << std::endl;

	} catch (std::exception &e) {
		std::cout << "Unexpected error: " << e.what() << std::endl;
	}
	return 0;
}


