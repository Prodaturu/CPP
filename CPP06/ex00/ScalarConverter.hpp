#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

// Utility-only class: no instances, just a single entry point that
// parses one literal and prints conversions to all scalar types.
class ScalarConverter
{
	private:
		// Private canonical members to prevent instantiation/copying.
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

	public:
		// Detect input literal type, convert it, and print char/int/float/double.
		static void convert(const std::string& literal);
};

#endif
