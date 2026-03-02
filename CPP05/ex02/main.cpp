/*
Concept Notes (ex02 - main.cpp)
- End-to-end polymorphic testing with three concrete AForm implementations.
- Execution lifecycle testing: unsigned execute failure, low-grade failures, success cases.
- Random behavior demonstration for robotomy using seeded std::rand().
- Scenario-driven tests remain isolated through reusable runCase() wrapper.
*/
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Utility wrapper so one exception does not stop all tests.
static void runCase(const std::string& title, void (*test)())
{
	std::cout << "\n[ " << title << " ]" << std::endl;
	try
	{
		test();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

// Happy path:
// - Bureaucrat signs and executes ShrubberyCreationForm.
static void shrubberySuccessCase()
{
	Bureaucrat manager("Manager", 100);
	ShrubberyCreationForm garden("home");

	std::cout << manager << std::endl;
	std::cout << garden << std::endl;

	manager.signForm(garden);
	manager.executeForm(garden);
}

// Failure path:
// - Attempt execution before signing.
static void executeUnsignedCase()
{
	Bureaucrat chief("Chief", 1);
	RobotomyRequestForm robot("Bender");

	std::cout << chief << std::endl;
	std::cout << robot << std::endl;

	chief.executeForm(robot);
}

// Failure path:
// - Grade too low for signing.
static void signTooLowCase()
{
	Bureaucrat intern("Intern", 150);
	PresidentialPardonForm pardon("Arthur Dent");

	std::cout << intern << std::endl;
	std::cout << pardon << std::endl;

	intern.signForm(pardon);
}

// Failure path:
// - Grade high enough to sign but too low to execute.
static void executeTooLowCase()
{
	Bureaucrat signer("Signer", 20);
	PresidentialPardonForm pardon("Ford Prefect");

	signer.signForm(pardon);

	Bureaucrat executor("Executor", 6);
	std::cout << executor << std::endl;
	executor.executeForm(pardon);
}

// Happy path:
// - Robotomy executed several times to observe random success/fail.
static void robotomyRandomCase()
{
	Bureaucrat surgeon("Surgeon", 1);
	RobotomyRequestForm robot("Marvin");

	surgeon.signForm(robot);
	surgeon.executeForm(robot);
	surgeon.executeForm(robot);
	surgeon.executeForm(robot);
}

int main()
{
	// Seed PRNG once for robotomy randomness.
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	runCase("shrubbery success", &shrubberySuccessCase);
	runCase("execute unsigned form", &executeUnsignedCase);
	runCase("sign with too low grade", &signTooLowCase);
	runCase("execute with too low grade", &executeTooLowCase);
	runCase("robotomy randomness", &robotomyRandomCase);

	return 0;
}
