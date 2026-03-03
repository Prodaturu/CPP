#pragma once
#ifndef SPAN_HPP
#define SPAN_HPP

#include <exception>
#include <vector>

class Span
{
	public:
		class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		Span();
		explicit Span(unsigned int capacity);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);

		// Adds a whole iterator range in one call.
		template <typename InputIterator>
		void addNumbers(InputIterator first, InputIterator last)
		{
			std::vector<int> values;
			for (; first != last; ++first)
				values.push_back(*first);
			if (_numbers.size() + values.size() > _capacity)
				throw SpanFullException();
			_numbers.insert(_numbers.end(), values.begin(), values.end());
		}

		unsigned int shortestSpan() const;
		unsigned int longestSpan() const;
		unsigned int size() const;
		unsigned int capacity() const;

	private:
		unsigned int      _capacity;
		std::vector<int> _numbers;
};

#endif
