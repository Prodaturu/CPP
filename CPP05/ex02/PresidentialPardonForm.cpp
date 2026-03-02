/*
Concept Notes (ex02 - PresidentialPardonForm.cpp)
- Simple execute() override demonstrates specialization via message-only action.
- Keeps business action tiny by reusing AForm permission checks first.
- Reinforces "inherit shared policy, customize effect" design pattern.
*/
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

/* --- --- --- Constructors & Canonical Definitions --- --- --- */

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target)
{
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* --- --- --- Getters --- --- --- */

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

/* --- --- --- Execution --- --- --- */

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
	// Shared checks: signed + executor grade.
	this->validateExecution(executor);

	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
