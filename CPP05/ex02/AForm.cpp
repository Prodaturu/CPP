#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* --- --- --- Constructors & Canonical Definitions --- --- --- */

AForm::AForm(const std::string& name, int signGrade, int executeGrade)
	: _name(name), _isSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	// Validate both grades on construction.
	if (signGrade < 1 || executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (signGrade > 150 || executeGrade > 150)
		throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
	// Virtual destructor for polymorphic deletion safety.
}

AForm::AForm(const AForm& other)
	: _name(other._name),
		_isSigned(other._isSigned),
		_signGrade(other._signGrade),
		_executeGrade(other._executeGrade)
{
}

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other)
	{
		// const fields stay unchanged; only mutable signed state is copied.
		this->_isSigned = other._isSigned;
	}
	return *this;
}

/* --- --- --- Getters --- --- --- */

const std::string& AForm::getName() const
{
	return this->_name;
}

bool AForm::getIsSigned() const
{
	return this->_isSigned;
}

int AForm::getSignGrade() const
{
	return this->_signGrade;
}

int AForm::getExecuteGrade() const
{
	return this->_executeGrade;
}

/* --- --- --- Business Logic --- --- --- */

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	// Lower or equal numeric grade means sufficient rank.
	if (bureaucrat.getGrade() > this->_signGrade)
		throw AForm::GradeTooLowException();
	this->_isSigned = true;
}

void AForm::validateExecution(const Bureaucrat& executor) const
{
	if (!this->_isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > this->_executeGrade)
		throw AForm::GradeTooLowException();
}

/* --- --- --- Exceptions --- --- --- */

const char* AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high.";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low.";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed.";
}

/* --- --- --- Stream Output --- --- --- */

std::ostream& operator<<(std::ostream& os, const AForm& form)
{
	os << "AForm \"" << form.getName() << "\""
		<< " | signed: " << (form.getIsSigned() ? "yes" : "no")
		<< " | grade to sign: " << form.getSignGrade()
		<< " | grade to execute: " << form.getExecuteGrade();
	return os;
}
