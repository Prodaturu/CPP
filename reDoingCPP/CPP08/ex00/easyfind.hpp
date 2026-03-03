#pragma once
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

template <typename T>
typename T::iterator easyfind(T &container, int value);

template <typename T>
typename T::const_iterator easyfind(const T &container, int value);

class NotFoundException : public std::exception
{
	public:
		// Raised when the searched integer does not exist in the container.
		virtual const char *what() const throw()
		{
			return "value not found in container";
		}
};

#include "easyfind.tpp"

#endif
