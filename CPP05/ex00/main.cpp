/*
Concept Notes (ex00 - main.cpp)
- Test harness pattern: runCase() isolates scenarios so one exception does not stop all tests.
- Boundary-value testing: explicitly test grade 1 and 150 edge behavior.
- Exception handling in caller: catch std::exception to display failure reasons.
*/
#include "Bureaucrat.hpp"
#include <iostream>

// Small utility runner:
// - prints a case title
// - executes the test function
// - catches std::exception so one failing case does not stop later cases
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

// Happy-path case: construct a valid Bureaucrat and move grade up/down once.
static void validFlow()
{
	Bureaucrat bob("Bob", 67);
	std::cout << bob << std::endl;
	bob.incrementGrade();
	std::cout << bob << std::endl;
	bob.decrementGrade();
	std::cout << bob << std::endl;
}

// Constructor should reject grade 0 (too high).
static void invalidHighOnConstruction()
{
	Bureaucrat ali("Ali", 0);
	std::cout << ali << std::endl;
}

// Constructor should reject grade 151 (too low).
static void invalidLowOnConstruction()
{
	Bureaucrat eve("Eve", 151);
	std::cout << eve << std::endl;
}

// Boundary case: cannot increment from grade 1 to grade 0.
static void highBoundaryIncrement()
{
	Bureaucrat top("Top", 1);
	std::cout << top << std::endl;
	top.incrementGrade();
}

// Boundary case: cannot decrement from grade 150 to grade 151.
static void lowBoundaryDecrement()
{
	Bureaucrat low("Low", 150);
	std::cout << low << std::endl;
	low.decrementGrade();
}

// made seperate runcase() function to run each case seperately
// catch the exception in each case 
// so that one failing case does not stop the execution of later cases

// catching happens in the main function when we call runCase() for each test case,
// so that we can show all expected outcomes in one run, even if some cases throw exceptions
// this doesnt stop compared to having the try catch block inside each test case
// because we want to show all expected outcomes in one run, even if some cases throw exceptions
int	main()
{
	// Run every case independently to show all expected outcomes in one run.
	runCase("valid flow", &validFlow);
	runCase("constructor grade too high", &invalidHighOnConstruction);
	runCase("constructor grade too low", &invalidLowOnConstruction);
	runCase("increment beyond grade 1", &highBoundaryIncrement);
	runCase("decrement beyond grade 150", &lowBoundaryDecrement);
	return 0;
}
