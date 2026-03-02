#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// Utility wrapper to keep each scenario isolated.
// One failing case should not stop the whole test run.
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

// Successful signing flow:
// Alice grade 40 can sign a form that requires grade 50.
static void successfulSigningCase()
{
	Bureaucrat alice("Alice", 40);
	Form travelRequest("Travel Request", 50, 20);

	std::cout << alice << std::endl;
	std::cout << travelRequest << std::endl;

	alice.signForm(travelRequest);
	std::cout << travelRequest << std::endl;
}

// Failed signing flow:
// Bob grade 120 cannot sign a form that requires grade 80.
static void failedSigningCase()
{
	Bureaucrat bob("Bob", 120);
	Form secretForm("Secret Form", 80, 30);

	std::cout << bob << std::endl;
	std::cout << secretForm << std::endl;

	bob.signForm(secretForm);
	std::cout << secretForm << std::endl;
}

// Invalid form construction: sign grade too high (0).
static void formInvalidHighGrade()
{
	Form impossible("Impossible", 0, 50);
	std::cout << impossible << std::endl;
}

// Invalid form construction: execute grade too low (151).
static void formInvalidLowGrade()
{
	Form impossible("Impossible", 20, 151);
	std::cout << impossible << std::endl;
}

// Boundary check for Bureaucrat is still important in ex01.
static void bureaucratBoundaryCase()
{
	Bureaucrat chief("Chief", 1);
	std::cout << chief << std::endl;
	chief.incrementGrade();
}

int	main()
{
	// ex01 checks:
	// 1) successful sign
	// 2) failed sign due to low bureaucrat rank
	// 3) form constructor grade validation
	// 4) bureaucrat boundary exception behavior
	runCase("successful signing", &successfulSigningCase);
	runCase("failed signing", &failedSigningCase);
	runCase("form invalid high grade", &formInvalidHighGrade);
	runCase("form invalid low grade", &formInvalidLowGrade);
	runCase("bureaucrat boundary check", &bureaucratBoundaryCase);
	return 0;
}
