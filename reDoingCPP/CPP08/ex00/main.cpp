#include "easyfind.hpp"
#include <deque>
#include <iostream>
#include <list>
#include <vector>

template <typename T>
void runTest(const char *containerName, const T &container, int target)
{
	std::cout << containerName << " search for " << target << ": ";
	try
	{
		// easyfind returns an iterator to the first match.
		typename T::const_iterator it = easyfind(container, target);
		std::cout << "found (" << *it << ")" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	std::vector<int> values;
	std::list<int> linkedValues;
	std::deque<int> queuedValues;

	values.push_back(42);
	values.push_back(54);
	values.push_back(76);
	values.push_back(12);

	linkedValues.push_back(4);
	linkedValues.push_back(8);
	linkedValues.push_back(15);
	linkedValues.push_back(16);

	queuedValues.push_back(23);
	queuedValues.push_back(42);
	queuedValues.push_back(108);

	runTest("vector", values, 54);
	runTest("vector", values, 999);
	runTest("list", linkedValues, 15);
	runTest("list", linkedValues, -3);
	runTest("deque", queuedValues, 108);
	runTest("deque", queuedValues, 7);

	return 0;
}
