#include "Bureaucrat.hpp"

									/* --- Constructor & Destructor --- */

// Constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

// Copy Constructor - to ensure proper copying of const member 'name'
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	if (_grade < 1)
		throw GradeTooHighException();
	if (_grade > 150)
		throw GradeTooLowException();
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Assignment Operator
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		// name is const, so we don't assign it
		_grade = other._grade;
	}
	return *this;
}

// Getters
const std::string& Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

									/** --- Grade modification methods --- */

void Bureaucrat::incrementGrade()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
}

void Bureaucrat::decrementGrade()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
}

// Exception what() implementations
const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low! Minimum grade is 150.";
}

// Overload of the insertion operator for easy printing
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade();
	return os;
}
