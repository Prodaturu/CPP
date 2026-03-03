#include "ScalarConverter.hpp"

#include <iostream>

// Entry point for ex00:
// expects exactly one literal argument and delegates conversion/printing.
int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: ./convert <literal>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
