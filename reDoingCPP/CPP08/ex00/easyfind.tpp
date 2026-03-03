#ifndef EASYFIND_TPP
#define EASYFIND_TPP

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	// Find first occurrence of the target integer in a mutable container.
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	// Const overload for read-only containers.
	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end())
		throw NotFoundException();
	return it;
}

#endif
