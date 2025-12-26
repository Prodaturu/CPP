#include<iostream>
#include<cctype>

int main(int argc, char **argv)
{
	// if no msg to convert print error msg and exit
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	/* Changing the given arguments to uppercase and printing them*/
	
	// for each argument in argv
	// start from 1 to skip program name
	for (int i = 1; i < argc; i++)
	{
		// for each character in the argument string
		// iterate through each character in the argument string
		for (int j = 0; argv[i][j]; j++)
		{
			// convert to uppercase and print
			std::cout << std::toupper(static_cast<unsigned char>(argv[i][j]));
		}

		// print space after argument if its not the last one
		if (i < argc - 1)
			std::cout << ' ';
	}

	// print newline at the end of output and exit
	std::cout << std::endl;
	return 0;
}

/** std::cout << std::toupper(static_cast<unsigned char>(argv[i][j]));
 * 
 * The line of code is used to convert a char to its uppercase equivalent
 * and print it to the standard output stream (console).
 * 
 * Here's a breakdown of the components:
 * std::cout: Standard output stream in C++ used for printing to console
 * 
 * std::toupper: Fn used to convert a lowercase letter to uppercase
 * 
 * static_cast<unsigned char>(argv[i][j]):
 * This part casts the character argv[i][j] to an unsigned char type.
 * 
 * The cast is necessary as the std::toupper function expects an int argument
 * that is either EOF or representable as an unsigned char.
 * some char values may be negative when interpreted as signed char
 * so casting to unsigned char ensures correct behavior
 */

/** Casting in C++
 * 
 * Casting is the process of converting a variable from one data type to another
 * In c++
 * 	there are several types of casting
 * 	1. implicit casting
 * 	2. explicit casting
 * 	3. static_cast
 * 	4. dynamic_cast
 * 	5. const_cast
 * 	6. reinterpret_cast
 * 
 */

/** static_cast
 * 
 * static_cast is a type of explicit casting in C++
 * It is used to convert one data type to another at compile time
 * It is safer than C-style casting as it provides better type checking
 *
 * Example:
 * 	int a = 10;
 * 	double b = static_cast<double>(a); // converts
 * 	char c = 'A';
 * 	int d = static_cast<int>(c); // converts
 * 
 */
