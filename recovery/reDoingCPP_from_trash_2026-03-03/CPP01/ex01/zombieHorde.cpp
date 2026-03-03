#include "Zombie.hpp"

// It must allocate N Zombie objects in a single allocation. Then, it must initialize the
// zombies, giving each of them the name passed as a parameter. The function returns a
// pointer to the first zombie
// prefer using new[] and delete[] for arrays in C++

Zombie* zombieHorde( int N, const std::string& name )
{
	if (N <= 0)	// Handle invalid input
		return nullptr;

	Zombie* horde = new Zombie[N];		// Create array of N Zombies on heap

	int i = 0;

	while (i < N) 						// Initialize each Zombie in the array
	{
		// Initialize each Zombie with the given name
		horde[i] = Zombie(name + "_" + std::to_string(i + 1));
		i++;
	}

	return horde;
}