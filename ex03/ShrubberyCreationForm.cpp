#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default_target") {}

// Parametrized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src), _target(src._target) {}

// Copy Assignment constructor
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	if (this != &rhs){
		AForm::operator=(rhs);
		// _target is const, so it cannot be reassigned
	}
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/**
 * The execute function validates:
 * - if the form is signed
 * - if the executor's grade is high enough
 * using a base class method.
 */
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	// Elegant check: throws exception if not signed or grade too low
	this->checkExecutability(executor);

	std::string fileName = _target + "_shrubbery";
	std::ofstream outfile(fileName.c_str());

	if(!outfile.is_open()) {
		std::cerr << "Error: Could not create file " << fileName << std::endl;
		return;
	}

// ASCII Trees as requested by the subject
outfile << "        v        " << std::endl;
outfile << "       >X<       " << std::endl;
outfile << "        A        " << std::endl;
outfile << "       d$b       " << std::endl;
outfile << "    .d\\|$$b.    " << std::endl;
outfile << "  .d$i$$|\\$$b.  " << std::endl;
outfile << "      d$$@b      " << std::endl;
outfile << "     d\\$$ib     " << std::endl;
outfile << "   .d$$$\\$$b    " << std::endl;
outfile << " .d$$@$$$\\$$ib. " << std::endl;
outfile << "    .d$$$$$b.    " << std::endl;
outfile << "  .d$$i$$\\$$b.  " << std::endl;
outfile << "       ###       " << std::endl;
outfile << "       ###       " << std::endl;

outfile.close();
}