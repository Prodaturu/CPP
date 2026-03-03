#include "BitcoinExchange.hpp"

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

// Default constructor: map starts empty until loadRates() is called.
BitcoinExchange::BitcoinExchange()
{
}

// Copy constructor: std::map copy is deep for contained values.
BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _rates(other._rates)
{
}

// Assignment operator: guard self-assignment and copy map contents.
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_rates = other._rates;
	return *this;
}

// Destructor: no manual cleanup needed, STL handles internal memory.
BitcoinExchange::~BitcoinExchange()
{
}

// Gregorian leap-year rule.
bool BitcoinExchange::isLeapYear(int year) const
{
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Strict date validator for format YYYY-MM-DD and valid calendar day.
bool BitcoinExchange::isValidDate(const std::string &date) const
{
	// Quick format check first.
	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	// Ensure all non-separator chars are digits.
	for (std::size_t i = 0; i < date.length(); ++i)
	{
		if (i == 4 || i == 7)
			continue;
		if (date[i] < '0' || date[i] > '9')
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	// Basic month/day bounds.
	if (month < 1 || month > 12 || day < 1)
		return false;

	// Day count per month, adjusted for leap years in February.
	int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (month == 2 && isLeapYear(year))
		monthDays[1] = 29;

	return day <= monthDays[month - 1];
}

// Parse a floating-point number and reject trailing garbage.
bool BitcoinExchange::parseValue(const std::string &valueStr, double &value) const
{
	std::stringstream ss(valueStr);
	ss >> value;
	if (ss.fail())
		return false;
	char extra;
	if (ss >> extra)
		return false;
	return true;
}

// Load historical rates from CSV.
// Expected header: date,exchange_rate
void BitcoinExchange::loadRates(const std::string &csvPath)
{
	std::ifstream file(csvPath.c_str());
	if (!file.is_open())
		throw std::runtime_error("Error: could not open file.");

	std::string line;
	// Consume header line; if file is empty, fail fast.
	if (!std::getline(file, line))
		throw std::runtime_error("Error: empty database.");

	// Parse each data line; malformed lines are ignored.
	while (std::getline(file, line))
	{
		if (line.empty())
			continue;

		std::size_t commaPos = line.find(',');
		if (commaPos == std::string::npos)
			continue;

		std::string date = line.substr(0, commaPos);
		std::string valueStr = line.substr(commaPos + 1);
		double rate;

		// Keep only valid date + non-negative numeric rate entries.
		if (!isValidDate(date) || !parseValue(valueStr, rate) || rate < 0.0)
			continue;

		_rates[date] = rate;
	}

	if (_rates.empty())
		throw std::runtime_error("Error: no valid rates in database.");
}

// Process user file with "date | value" lines and print exchange result.
void BitcoinExchange::processInput(const std::string &inputPath) const
{
	std::ifstream file(inputPath.c_str());
	if (!file.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return;
	}

	std::string line;
	// First line is expected to be the exact header "date | value".
	if (!std::getline(file, line))
		return;

	bool processCurrentLine = (line != "date | value");
	// If header is missing/malformed, do not silently drop the first line.
	// Process it as data so user gets explicit feedback.
	while (true)
	{
		if (processCurrentLine)
		{
			if (!line.empty())
			{
				// Strict separator expected by subject examples.
				std::size_t pipePos = line.find(" | ");
				if (pipePos == std::string::npos)
				{
					std::cerr << "Error: bad input => " << line << std::endl;
				}
				else
				{
					std::string date = line.substr(0, pipePos);
					std::string valueStr = line.substr(pipePos + 3);

					double amount;
					// Validate date and numeric payload.
					if (!isValidDate(date) || !parseValue(valueStr, amount))
					{
						std::cerr << "Error: bad input => " << line << std::endl;
					}
					// Subject constraints for amount range.
					else if (amount < 0.0)
					{
						std::cerr << "Error: not a positive number." << std::endl;
					}
					else if (amount > 1000.0)
					{
						std::cerr << "Error: too large a number." << std::endl;
					}
					else
					{
						// Find exact date or closest previous date in ordered map.
						std::map<std::string, double>::const_iterator it = _rates.lower_bound(date);
						if (it == _rates.end() || it->first != date)
						{
							// No earlier data available.
							if (it == _rates.begin())
							{
								std::cerr << "Error: bad input => " << line << std::endl;
							}
							else
							{
								// Step back to latest rate before requested date.
								--it;
								double result = amount * it->second;
								std::cout << date << " => " << amount << " = " << result << std::endl;
							}
						}
						else
						{
							double result = amount * it->second;
							std::cout << date << " => " << amount << " = " << result << std::endl;
						}
					}
				}
			}
		}

		if (!std::getline(file, line))
			break;
		processCurrentLine = true;
	}
}
