#include "PmergeMe.hpp"

#include <algorithm>
#include <climits>
#include <cstdlib>
#include <sstream>
#include <stdexcept>

// Private default constructor prevents direct object creation.
PmergeMe::PmergeMe()
{
}

// Canonical copy constructor.
PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

// Canonical assignment operator.
PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

// Canonical destructor.
PmergeMe::~PmergeMe()
{
}

// Convert argv inputs to validated positive integers.
// Rules:
// - at least one number required
// - each token must contain only digits
// - value must fit in int range and be non-negative
std::vector<int> PmergeMe::parseInput(int argc, char **argv)
{
	if (argc < 2)
		throw std::runtime_error("Error");

	std::vector<int> numbers;
	// Parse each command-line token independently.
	for (int i = 1; i < argc; ++i)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw std::runtime_error("Error");

		// Reject signs, spaces, and non-digit characters.
		for (std::size_t j = 0; j < token.length(); ++j)
		{
			if (token[j] < '0' || token[j] > '9')
				throw std::runtime_error("Error");
		}

		// Safe conversion then range check.
		long value = std::strtol(token.c_str(), NULL, 10);
		if (value < 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		// Store as int once validated.
		numbers.push_back(static_cast<int>(value));
	}
	return numbers;
}

// Sort with vector.
std::vector<int> PmergeMe::sortVector(const std::vector<int> &input)
{
	std::vector<int> out(input);
	std::sort(out.begin(), out.end());
	return out;
}

// Sort with deque.
std::deque<int> PmergeMe::sortDeque(const std::vector<int> &input)
{
	std::deque<int> out(input.begin(), input.end());
	std::sort(out.begin(), out.end());
	return out;
}

// Verify non-decreasing order for vector result.
bool PmergeMe::isSorted(const std::vector<int> &values)
{
	for (std::size_t i = 1; i < values.size(); ++i)
	{
		if (values[i - 1] > values[i])
			return false;
	}
	return true;
}

// Verify non-decreasing order for deque result.
bool PmergeMe::isSorted(const std::deque<int> &values)
{
	for (std::size_t i = 1; i < values.size(); ++i)
	{
		if (values[i - 1] > values[i])
			return false;
	}
	return true;
}

// Build space-separated representation of sequence values.
std::string PmergeMe::joinVector(const std::vector<int> &values)
{
	std::ostringstream oss;
	for (std::size_t i = 0; i < values.size(); ++i)
	{
		if (i != 0)
			oss << " ";
		oss << values[i];
	}
	return oss.str();
}
