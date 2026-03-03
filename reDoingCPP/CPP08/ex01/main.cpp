#include "Span.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main()
{
	{
		std::cout << "subject example:" << std::endl;
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	{
		std::cout << "\nexception checks:" << std::endl;
		try
		{
			Span tooSmall(1);
			tooSmall.addNumber(42);
			std::cout << tooSmall.shortestSpan() << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}

		try
		{
			Span full(2);
			full.addNumber(1);
			full.addNumber(2);
			full.addNumber(3);
		}
		catch (const std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	{
		std::cout << "\n10,000 numbers test:" << std::endl;
		std::srand(static_cast<unsigned int>(std::time(NULL)));
		std::vector<int> values;
		values.reserve(10000);
		for (int i = 0; i < 10000; ++i)
			values.push_back(std::rand());

		Span large(10000);
		large.addNumbers(values.begin(), values.end());
		std::cout << "stored: " << large.size() << std::endl;
		std::cout << "shortest span: " << large.shortestSpan() << std::endl;
		std::cout << "longest span: " << large.longestSpan() << std::endl;
	}

	return 0;
}
