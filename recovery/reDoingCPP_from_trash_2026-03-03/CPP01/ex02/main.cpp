#include <string.h>
#include <iostream>

// Write a program that contains:
// • A string variable initialized to "HI THIS IS BRAIN".
// • stringPTR: a pointer to the string.
// • stringREF: a reference to the string.
// Your program must print:
// • The memory address of the string variable.
// • The memory address held by stringPTR.
// • The memory address held by stringREF.
// And then:
// • The value of the string variable.
// • The value pointed to by stringPTR.
// • The value pointed to by stringREF.
// That’s all—no tricks.

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string* stringPTR = &str;		// Pointer to the string
	std::string& stringREF = str;		// Reference to the string

	// Print memory addresses
	std::cout << "Memory address of string variable: " << &str << std::endl;		// Address of the string variable
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;	// Address held by the pointer
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;	// Address held by the reference (same as the string variable)

	// Print values
	std::cout << "Value of the string variable: " << str << std::endl;				// Value of the string variable
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;		// Value pointed to by the pointer
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;		// Value pointed to by the reference

	return 0;
}
