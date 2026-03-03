#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <exception>
#include <iostream>

// Randomly build one derived type and return it via Base pointer.
Base* generate(void)
{
	int pick = std::rand() % 3;
	if (pick == 0)
		return new A();
	if (pick == 1)
		return new B();
	return new C();
}

// Pointer version: failed dynamic_cast to pointer yields NULL.
void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C" << std::endl;
}

// Reference version: failed dynamic_cast throws, so we probe in sequence.
void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (const std::exception&)
	{
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (const std::exception&)
	{
	}
}
