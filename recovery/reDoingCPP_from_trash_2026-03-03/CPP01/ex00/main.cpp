#include "Zombie.hpp"
#include "iostream"


int	main()
{
	Zombie	*heapZombie;

	// create a zombie on temp memory (stack) and announce it
	// memory allocation and freeing is automatic
	randomChump("temporary zombie on stack");

	// create a zombie on heap 
		// allocated memory needs to be manually handled
	// failing to free this would lead to loss of memory
	heapZombie = newZombie("zombie on heap");

	if (heapZombie)
	return(heapZombie->announce(), delete(heapZombie), 0); // return 1 to indicate error

	
	return 0;
}

/** Logic:

 * 1. Create a temporary zombie on the stack using the randomChump function.
 * 2. Create a zombie on the heap using the newZombie function.
 * 3. If the heap zombie is successfully created, announce it and free the allocated memory.
 * 4. Return 0 to indicate successful execution.

*/
