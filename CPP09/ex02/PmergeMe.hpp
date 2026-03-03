#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <string>
#include <vector>

// PmergeMe helper class for CPP09/ex02.
//
// This implementation provides:
// - input parsing/validation from argv
// - sorting through std::vector and std::deque
// - sortedness checks
// - display utility for "Before" / "After" lines
class PmergeMe
{
private:
	// Non-instantiable utility style (all public methods are static).
	PmergeMe();

public:
	// Canonical operations present for completeness.
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	// Parse argv[1..] into positive integer sequence.
	// Throws runtime_error("Error") on any invalid token.
	static std::vector<int> parseInput(int argc, char **argv);

	// Sort helpers for each container type.
	static std::vector<int> sortVector(const std::vector<int> &input);
	static std::deque<int> sortDeque(const std::vector<int> &input);

	// Post-condition checks.
	static bool isSorted(const std::vector<int> &values);
	static bool isSorted(const std::deque<int> &values);

	// Utility to print input/result sequences in one line.
	static std::string joinVector(const std::vector<int> &values);
};

#endif
