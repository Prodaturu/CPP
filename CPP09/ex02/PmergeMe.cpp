#include "PmergeMe.hpp"

#include <climits>
#include <cstdlib>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <deque>

namespace
{
	// Build Jacobsthal-guided insertion order for pending elements.
	// This follows the usual Ford-Johnson idea of inserting groups in reverse
	// within Jacobsthal boundaries.
	static std::vector<std::size_t> buildInsertionOrder(std::size_t count)
	{
		std::vector<std::size_t> order;
		if (count == 0)
			return order;

		std::size_t prev = 0;
		long jm2 = 0; // J(1)
		long jm1 = 1; // J(2)

		while (true)
		{
			long j = jm1 + 2 * jm2; // next Jacobsthal
			jm2 = jm1;
			jm1 = j;

			if (j <= 0)
				break;

			std::size_t boundary = static_cast<std::size_t>(j);
			if (boundary > count)
				boundary = count;
			if (boundary <= prev)
				break;

			// Insert this group in reverse order.
			for (std::size_t i = boundary; i > prev; --i)
				order.push_back(i - 1);
			prev = boundary;

			if (prev == count)
				break;
		}

		// Any remaining indices (if Jacobsthal sequence did not reach all count).
		for (std::size_t i = count; i > prev; --i)
			order.push_back(i - 1);

		return order;
	}

	static void binaryInsertVector(std::vector<int> &values, int value)
	{
		std::size_t left = 0;
		std::size_t right = values.size();
		while (left < right)
		{
			std::size_t mid = left + (right - left) / 2;
			if (values[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		values.insert(values.begin() + static_cast<std::ptrdiff_t>(left), value);
	}

	static std::vector<int> fordJohnsonVector(const std::vector<int> &input)
	{
		if (input.size() <= 1)
			return input;

		std::vector<int> mainChain;
		std::vector<int> pending;
		bool hasStraggler = false;
		int straggler = 0;

		// Pair elements; keep larger in main chain candidates, smaller in pending.
		for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		{
			int a = input[i];
			int b = input[i + 1];
			if (a < b)
			{
				mainChain.push_back(b);
				pending.push_back(a);
			}
			else
			{
				mainChain.push_back(a);
				pending.push_back(b);
			}
		}

		if (input.size() % 2 != 0)
		{
			hasStraggler = true;
			straggler = input[input.size() - 1];
		}

		// Recursively sort the main chain.
		mainChain = fordJohnsonVector(mainChain);

		// Insert pending elements using Jacobsthal-guided order.
		std::vector<std::size_t> order = buildInsertionOrder(pending.size());
		for (std::size_t i = 0; i < order.size(); ++i)
			binaryInsertVector(mainChain, pending[order[i]]);

		if (hasStraggler)
			binaryInsertVector(mainChain, straggler);

		return mainChain;
	}

	static void binaryInsertDeque(std::deque<int> &values, int value)
	{
		std::size_t left = 0;
		std::size_t right = values.size();
		while (left < right)
		{
			std::size_t mid = left + (right - left) / 2;
			if (values[mid] < value)
				left = mid + 1;
			else
				right = mid;
		}
		values.insert(values.begin() + static_cast<std::ptrdiff_t>(left), value);
	}

	static std::deque<int> fordJohnsonDeque(const std::deque<int> &input)
	{
		if (input.size() <= 1)
			return input;

		std::deque<int> mainChain;
		std::deque<int> pending;
		bool hasStraggler = false;
		int straggler = 0;

		for (std::size_t i = 0; i + 1 < input.size(); i += 2)
		{
			int a = input[i];
			int b = input[i + 1];
			if (a < b)
			{
				mainChain.push_back(b);
				pending.push_back(a);
			}
			else
			{
				mainChain.push_back(a);
				pending.push_back(b);
			}
		}

		if (input.size() % 2 != 0)
		{
			hasStraggler = true;
			straggler = input[input.size() - 1];
		}

		mainChain = fordJohnsonDeque(mainChain);

		std::vector<std::size_t> order = buildInsertionOrder(pending.size());
		for (std::size_t i = 0; i < order.size(); ++i)
			binaryInsertDeque(mainChain, pending[order[i]]);

		if (hasStraggler)
			binaryInsertDeque(mainChain, straggler);

		return mainChain;
	}
}

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
// - value must fit in int range and be strictly positive
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
		if (value <= 0 || value > INT_MAX)
			throw std::runtime_error("Error");

		// Store as int once validated.
		numbers.push_back(static_cast<int>(value));
	}
	return numbers;
}

// Sort with vector.
std::vector<int> PmergeMe::sortVector(const std::vector<int> &input)
{
	return fordJohnsonVector(input);
}

// Sort with deque.
std::deque<int> PmergeMe::sortDeque(const std::vector<int> &input)
{
	std::deque<int> start(input.begin(), input.end());
	return fordJohnsonDeque(start);
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
