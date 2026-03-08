#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		const std::string _target;

	public:
		// Default Constructor
		ShrubberyCreationForm();

		// Parametrized Constructor
		ShrubberyCreationForm(const std::string target);

		// Copy Constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& src);

		// Copy Assignment Operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		// Destructor
		virtual ~ShrubberyCreationForm();

		// Executor
		void	execute(Bureaucrat const & executor) const;
};

#endif