#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

/* --- --- --- Constructors & Canonical Definitions --- --- --- */

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target)
{
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* --- --- --- Getters --- --- --- */

const std::string& ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

/* --- --- --- Execution --- --- --- */

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{
	// Shared checks: signed + executor grade.
	this->validateExecution(executor);

	const std::string filename = this->_target + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out.is_open())
		throw ShrubberyCreationForm::FileOpenException();

	// Write a simple ASCII tree.
	out << "       _-_" << std::endl;
	out << "    /~~   ~~\\" << std::endl;
	out << " /~~         ~~\\" << std::endl;
	out << "{               }" << std::endl;
	out << " \\  _-     -_  /" << std::endl;
	out << "   ~  \\\\ //  ~" << std::endl;
	out << "_- -   | | _- _" << std::endl;
	out << "  _ -  | |   -_" << std::endl;
	out << "      // \\\\" << std::endl;
}

/* --- --- --- Exceptions --- --- --- */

const char* ShrubberyCreationForm::FileOpenException::what() const throw()
{
	return "Failed to open shrubbery output file.";
}
