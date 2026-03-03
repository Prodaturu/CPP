#include "ScalarConverter.hpp"

#include <cctype>
#include <cerrno>
#include <climits>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

// Intentionally non-instantiable class: private constructors/destructor are defined
// to satisfy the linker if they are ever referenced internally.
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other)
{
	(void)other;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

// Helpers to recognize subject-mandated pseudo literals.
static bool isPseudoDouble(const std::string& s)
{
	return s == "nan" || s == "+inf" || s == "-inf";
}

static bool isPseudoFloat(const std::string& s)
{
	return s == "nanf" || s == "+inff" || s == "-inff";
}

// Accepts single printable char (e.g. a) or quoted char (e.g. 'a').
static bool isCharLiteral(const std::string& s)
{
	if (s.length() == 1 && !std::isdigit(static_cast<unsigned char>(s[0])))
		return true;
	if (s.length() == 3 && s[0] == '\'' && s[2] == '\'')
		return true;
	return false;
}

// Integer form: optional sign + one or more digits.
static bool isIntLiteral(const std::string& s)
{
	if (s.empty())
		return false;
	std::size_t i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (i == s.length())
		return false;
	for (; i < s.length(); i++)
	{
		if (!std::isdigit(static_cast<unsigned char>(s[i])))
			return false;
	}
	return true;
}

// Float form must end with 'f'. We parse the numeric prefix with strtod
// to validate syntax while keeping C++98 compatibility.
static bool isFloatLiteral(const std::string& s)
{
	if (s.length() < 2 || s[s.length() - 1] != 'f')
		return false;
	if (isPseudoFloat(s))
		return true;
	char* end = NULL;
	errno = 0;
	std::strtod(s.substr(0, s.length() - 1).c_str(), &end);
	return errno != ERANGE && end && *end == '\0';
}

// Double form is a generic decimal string (plus pseudo literals handled above).
static bool isDoubleLiteral(const std::string& s)
{
	if (isPseudoDouble(s))
		return true;
	char* end = NULL;
	errno = 0;
	std::strtod(s.c_str(), &end);
	return errno != ERANGE && end && *end == '\0';
}

// Keep output formatting close to subject examples:
// - integral values show one decimal place (42.0 / 42.0f)
// - fractional values keep precision
// - pseudo literals are printed explicitly.
static std::string formatFloating(double value, bool asFloat)
{
	if (std::isnan(value))
		return asFloat ? "nanf" : "nan";
	if (std::isinf(value))
	{
		if (value < 0)
			return asFloat ? "-inff" : "-inf";
		return asFloat ? "+inff" : "+inf";
	}

	std::ostringstream oss;
	if (value == std::floor(value))
		oss << std::fixed << std::setprecision(1) << value;
	else
		oss << std::setprecision(15) << value;
	if (asFloat)
		oss << 'f';
	return oss.str();
}

void ScalarConverter::convert(const std::string& literal)
{
	double value;

	// 1) Detect input kind and normalize into one common intermediate: double.
	if (isCharLiteral(literal))
	{
		char c = literal.length() == 1 ? literal[0] : literal[1];
		value = static_cast<double>(c);
	}
	else if (isPseudoFloat(literal))
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	else if (isPseudoDouble(literal))
		value = std::strtod(literal.c_str(), NULL);
	else if (isIntLiteral(literal))
		value = static_cast<double>(std::strtol(literal.c_str(), NULL, 10));
	else if (isFloatLiteral(literal))
		value = static_cast<double>(std::strtof(literal.c_str(), NULL));
	else if (isDoubleLiteral(literal))
		value = std::strtod(literal.c_str(), NULL);
	else
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	// 2) Print char conversion with display/range checks.
	std::cout << "char: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < std::numeric_limits<char>::min()
		|| value > std::numeric_limits<char>::max())
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		char c = static_cast<char>(value);
		if (std::isprint(static_cast<unsigned char>(c)))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	// 3) Print int conversion with NaN/Inf/overflow guards.
	std::cout << "int: ";
	if (std::isnan(value) || std::isinf(value)
		|| value < static_cast<double>(INT_MIN)
		|| value > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;

	// 4) Float and double are always printable (including special values).
	std::cout << "float: " << formatFloating(static_cast<float>(value), true) << std::endl;
	std::cout << "double: " << formatFloating(value, false) << std::endl;
}
