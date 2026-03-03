#include "Zombie.hpp"

int main()
{
	// Create a Zombie on heap & stack memory //

	Zombie* heapZombie = new Zombie("HeapZombie");	// Create on heap

	Zombie stackZombie("StackZombie"); 				// Create on stack

	// Announce both zombies
	heapZombie->announce();
	stackZombie.announce();

	delete heapZombie; 		// Clean up heap memory

	return 0;
}

/** Logic:

 * 1. Create horde of N zombies using zombieHorde()
 * 2. Each zombie announces itself
 * 3. Delete entire horde with delete[]
 * 4. All destructors called automatically
 
 */