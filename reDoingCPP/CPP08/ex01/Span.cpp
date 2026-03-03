#include "Span.hpp"

#include <algorithm>

const char *Span::SpanFullException::what() const throw()
{
	return "span is full";
}

const char *Span::NotEnoughNumbersException::what() const throw()
{
	return "at least two numbers are required";
}

Span::Span() : _capacity(0)
{
}

Span::Span(unsigned int capacity) : _capacity(capacity)
{
}

Span::Span(const Span &other) : _capacity(other._capacity), _numbers(other._numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_capacity = other._capacity;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _capacity)
		throw SpanFullException();
	_numbers.push_back(number);
}

unsigned int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());

	unsigned int shortest = static_cast<unsigned int>(
		static_cast<long>(sorted[1]) - static_cast<long>(sorted[0]));
	for (std::vector<int>::size_type i = 2; i < sorted.size(); ++i)
	{
		unsigned int current = static_cast<unsigned int>(
			static_cast<long>(sorted[i]) - static_cast<long>(sorted[i - 1]));
		if (current < shortest)
			shortest = current;
	}
	return shortest;
}

unsigned int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int>::const_iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return static_cast<unsigned int>(static_cast<long>(*maxIt) - static_cast<long>(*minIt));
}

unsigned int Span::size() const
{
	return static_cast<unsigned int>(_numbers.size());
}

unsigned int Span::capacity() const
{
	return _capacity;
}
