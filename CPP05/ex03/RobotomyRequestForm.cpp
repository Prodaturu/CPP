/*
Concept Notes (ex02 - RobotomyRequestForm.cpp)
- Override execute() with stochastic behavior (rand-based 50% success/failure).
- Preserves shared authorization checks via base-class validateExecution().
- Illustrates action reporting through console output for both possible outcomes.
*/
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <cstdlib>

/* --- --- --- Constructors & Canonical Definitions --- --- --- */

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target)
{
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

/* --- --- --- Getters --- --- --- */

const std::string& RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

/* --- --- --- Execution --- --- --- */

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
{
	// Shared checks: signed + executor grade.
	this->validateExecution(executor);

	std::cout << "* drilling noises *" << std::endl;

	// 50% success simulation.
	if (std::rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed on " << this->_target << "." << std::endl;
}
