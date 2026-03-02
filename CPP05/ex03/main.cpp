#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Utility wrapper so one failure does not stop all scenarios.
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
// Intern creates shrubbery form, bureaucrat signs and executes it.
static void shrubberyFromInternCase()
{
	Intern someRandomIntern;
	Bureaucrat manager("Manager", 1);

	AForm* form = someRandomIntern.makeForm("shrubbery creation", "office");
	if (form == NULL)
		return;

	std::cout << *form << std::endl;
	manager.signForm(*form);
	manager.executeForm(*form);
	delete form;
}

// Happy path:
// Intern creates robotomy form and we execute it multiple times.
static void robotomyFromInternCase()
{
	Intern someRandomIntern;
	Bureaucrat chief("Chief", 1);

	AForm* form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form == NULL)
		return;

	chief.signForm(*form);
	chief.executeForm(*form);
	chief.executeForm(*form);
	delete form;
}

// Happy path:
// Intern creates presidential pardon form.
static void pardonFromInternCase()
{
	Intern someRandomIntern;
	Bureaucrat president("President", 1);

	AForm* form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form == NULL)
		return;

	president.signForm(*form);
	president.executeForm(*form);
	delete form;
}

// Error path:
// Unknown form name should not crash; makeForm returns NULL.
static void unknownFormCase()
{
	Intern someRandomIntern;
	AForm* form = someRandomIntern.makeForm("coffee form", "kitchen");
	if (form == NULL)
		std::cout << "Received NULL for unknown form as expected." << std::endl;
	delete form;
}

int	main()
{
	// Seed randomness for robotomy outcomes.
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	runCase("intern creates shrubbery", &shrubberyFromInternCase);
	runCase("intern creates robotomy", &robotomyFromInternCase);
	runCase("intern creates pardon", &pardonFromInternCase);
	runCase("intern unknown form", &unknownFormCase);
	return 0;
}
