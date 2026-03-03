#include "PmergeMe.hpp"

#include <ctime>
#include <deque>
#include <iostream>
#include <vector>

// Utility converting CPU clock ticks to microseconds.
static double elapsedMicroseconds(clock_t start, clock_t end)
{
	return static_cast<double>(end - start) * 1000000.0 / CLOCKS_PER_SEC;
}

// Entry point for CPP09/ex02.
// Example:
//   ./PmergeMe 3 5 9 7 4
int main(int argc, char **argv)
{
	try
	{
		// 1) Parse and validate all arguments.
		std::vector<int> input = PmergeMe::parseInput(argc, argv);
		std::cout << "Before: " << PmergeMe::joinVector(input) << std::endl;

		// 2) Time sorting with std::vector.
		clock_t vStart = std::clock();
		std::vector<int> sortedVector = PmergeMe::sortVector(input);
		clock_t vEnd = std::clock();

		// 3) Time sorting with std::deque.
		clock_t dStart = std::clock();
		std::deque<int> sortedDeque = PmergeMe::sortDeque(input);
		clock_t dEnd = std::clock();

		// 4) Defensive correctness check for both outputs.
		if (!PmergeMe::isSorted(sortedVector) || !PmergeMe::isSorted(sortedDeque))
		{
			std::cerr << "Error" << std::endl;
			return 1;
		}

		// 5) Print sorted output and timing report.
		std::cout << "After:  " << PmergeMe::joinVector(sortedVector) << std::endl;
		std::cout << "Time to process a range of " << input.size() << " elements with std::vector : "
			<< elapsedMicroseconds(vStart, vEnd) << " us" << std::endl;
		std::cout << "Time to process a range of " << input.size() << " elements with std::deque : "
			<< elapsedMicroseconds(dStart, dEnd) << " us" << std::endl;
	}
	catch (const std::exception &)
	{
		// Subject expects a single generic error text for invalid inputs.
		std::cerr << "Error" << std::endl;
		return 1;
	}

	return 0;
}
