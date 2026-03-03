#include "Bureaucrat.hpp"

int main() {
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
}