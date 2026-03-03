/*
Concept Notes (ex01 - Form.cpp)
- Constructor-level validation keeps every Form instance valid from birth.
- Partial assignment pattern: const members cannot be reassigned, only mutable state is copied.
- Interaction rule: beSigned() checks bureaucrat grade threshold.
- Rich object logging with operator<< for debugging and tests.
*/
#include "Form.hpp"
#include <iostream>

/* --- --- --- Constructors & Canonical Definitions --- --- --- */

Form::Form()
	: _name("DefaultForm"), _isSigned(false), _signGrade(150), _executeGrade(150)
{
}

// Main constructor:
// - starts unsigned
// - validates required grades immediately
Form::Form(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	// Sign grade and execute grade follow the same [1, 150] rule.
	if (signGrade < 1 || executeGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form()
{
	// No dynamic resources to release.
}

Form::Form(const Form& other)
	: _name(other._name),
		_isSigned(other._isSigned),
		_signGrade(other._signGrade),
		_executeGrade(other._executeGrade)
{
	// Everything initialized in initializer list.
}

Form& Form::operator=(const Form& other)
{
	if (this != &other)
	{
		// const fields cannot be re-assigned; only mutable state is _isSigned.
		this->_isSigned = other._isSigned;
	}
	return *this;
}

/* --- --- --- Getters --- --- --- */

const std::string& Form::getName() const
{
	return this->_name;
}

bool Form::getIsSigned() const
{
	return this->_isSigned;
}

int Form::getSignGrade() const
{
	return this->_signGrade;
}

int Form::getExecuteGrade() const
{
	return this->_executeGrade;
}

/* --- --- --- Business Logic --- --- --- */

// If bureaucrat grade is good enough (numerically <= required), sign the form.
// Otherwise throw GradeTooLowException.
void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->_signGrade)
		throw Form::GradeTooLowException();
	this->_isSigned = true;
}

/* --- --- --- Exceptions --- --- --- */

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high.";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low.";
}

/* --- --- --- Stream Output --- --- --- */

std::ostream& operator<<(std::ostream& os, const Form& form)
{
	os << "Form \"" << form.getName() << "\""
		<< " | signed: " << (form.getIsSigned() ? "yes" : "no")
		<< " | grade to sign: " << form.getSignGrade()
		<< " | grade to execute: " << form.getExecuteGrade();
	return os;
}
