#include "RPN.hpp"

#include <iostream>

// Entry point for CPP09/ex01.
// Expects exactly one quoted argument containing an RPN expression.
int main(int argc, char **argv)
{
	// Subject behavior: print "Error" on bad invocation.
	if (argc != 2)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try
	{
		// Evaluate and print final value.
		RPN rpn;
		std::cout << rpn.evaluate(argv[1]) << std::endl;
	}
	catch (const std::exception &e)
	{
		// Pass through evaluator's error text.
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
