#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

// BitcoinExchange
// ---------------
// Stores historical BTC exchange rates keyed by ISO date (YYYY-MM-DD)
// and evaluates input lines of the form:
//   date | value
// by multiplying the value with the matching rate for the date,
// or with the nearest previous available date.
class BitcoinExchange
{
private:
	// Ordered map lets us use lower_bound() to find exact/previous rates efficiently.
	std::map<std::string, double> _rates;

	// Date/value validation helpers used by database and input parsing.
	bool isLeapYear(int year) const;
	bool isValidDate(const std::string &date) const;
	bool parseValue(const std::string &valueStr, double &value) const;

public:
	// Orthodox Canonical Form.
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange();

	// Load CSV database (e.g., data.csv) with lines: date,exchange_rate
	// Invalid lines are skipped, valid lines populate _rates.
	void loadRates(const std::string &csvPath);

	// Read user input file with lines: date | value
	// Prints either computed result or explicit error messages per line.
	void processInput(const std::string &inputPath) const;
};

#endif
