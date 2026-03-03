#include "BitcoinExchange.hpp"

#include <iostream>

// Program entry for CPP09/ex00.
// Usage:
//   ./btc <input_file>
//
// It always loads exchange rates from local data.csv,
// then evaluates the given input file line by line.
int main(int argc, char **argv)
{
	// Must receive exactly one argument: input file path.
	if (argc != 2)
	{
		std::cerr << "Usage: ./btc <input_file>" << std::endl;
		return 1;
	}

	try
	{
		// Build exchange engine and load historical database.
		BitcoinExchange exchange;
		exchange.loadRates("data.csv");

		// Process user-provided transactions.
		exchange.processInput(argv[1]);
	}
	catch (const std::exception &e)
	{
		// Database/opening/parsing critical failures arrive here.
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
