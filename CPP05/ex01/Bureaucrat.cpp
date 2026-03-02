/*
Concept Notes (ex01 - Bureaucrat.cpp)
- Dependency expansion: Bureaucrat now uses Form behavior through Form.hpp.
- Responsibility split: Bureaucrat delegates signing rules to Form::beSigned().
- User-facing error reporting: signForm() catches exceptions and prints clear outcomes.
*/
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

/** @brief Initializer List
 * the syntax `ClassName::ClassName(parameters) : a(parameters)), b(parameter) ...`
 * 		is used to initialize member variables
 * This is called an "initializer list".
 * 
 * It is more efficient than assigning values inside the constructor body,
 * 		because it directly initializes the members
 * 		rather than default-constructing and then assigning.
 * 
 * For const members (like _name), they must be initialized in the initializer list
 * 		because they cannot be assigned to after construction.
 * 
 * Also, for members that are classes with no default constructor,
 * 		they must be initialized in the initializer list.
 * 
*/

/* --- --- --- Constructors & Cannonical Deinitions --- --- --- */

// parameterized constructor //
// initializes _name and _grade using initializer list
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	// the above line directly initializes _name and _grade
	// We validate immediately so no Bureaucrat object can ever exist with invalid state.
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

// default constructor //
// initializes _name to "fillerName" and _grade to 150
// Bureaucrat::Bureucrat() : _name("fillerName"), _grade(150)
// {
// 	// default constructor body can be empty since members are initialized above
// }

// 1. destructor //
// no special cleanup needed in this case as no dynamic memory is used
Bureaucrat::~Bureaucrat()
{
	// destructor body can be empty if no special cleanup is needed
}

// 2. copy constructor //
// initializes a new object as a copy of an existing object
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
	// copy constructor body can be empty since members are initialized above
}

// 3. copy assignment operator //
// assigns the values from existing object to another existing object (after both have been constructed)
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other) // check for self-assignment
	{
		// _name is const, so we cannot assign to it after construction
		// we can only assign to _grade
		this->_grade = other._grade;
	}
	return *this; // return the current object to allow chained assignments
}

/* --- --- --- Getters --- --- --- */

// return the name of the Bureaucrat
const	std::string &Bureaucrat::getName() const
{
	return this->_name;
}

// return the grade of the Bureaucrat
int Bureaucrat::getGrade() const
{
	return this->_grade;
}

/* --- --- --- Grade Modification --- --- --- */

// increment the grade (decrease the numerical value)
void Bureaucrat::incrementGrade()
{
	// Lower numeric value means "higher" bureaucrat grade.
	if (this -> _grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this -> _grade--;
}

// decrement the grade (increase the numerical value)
void Bureaucrat::decrementGrade()
{
	// Higher numeric value means "lower" bureaucrat grade.
	if (this->_grade + 1 > 150)
	{
		throw Bureaucrat::GradeTooLowException();
	}
	this->_grade++;
}

// ex01: Bureaucrat tries to sign a form.
// - On success: "<bureaucrat> signed <form>"
// - On failure: "<bureaucrat> couldn't sign <form> because <reason>"
void Bureaucrat::signForm(Form& form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

// what() returns a short human-readable reason for the exception.
// The returned string must remain valid, so we return a string literal.
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! Maximum grade is 1.";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! Minimum grade is 150.";
}

// Overload the insertion operator for easy printing of Bureaucrat details
// This keeps output formatting in one place and avoids duplicated print logic.
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return os;
}
