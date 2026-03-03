#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	// Seed rand once so each run produces a different A/B/C sequence.
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	// Exercise both identify overloads for multiple generated objects.
	for (int i = 0; i < 10; i++)
	{
		Base* instance = generate();
		std::cout << "identify(ptr): ";
		identify(instance);
		std::cout << "identify(ref): ";
		identify(*instance);
		delete instance;
	}
	return 0;
}
