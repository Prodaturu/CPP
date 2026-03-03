#include "Zombie.hpp"
#include <iostream>

// This function creates a zombie, names it,
// and makes it announce itself.

void	randomChump(const std::string& name)
{
    Zombie tempZombie(name); // Create a Zombie object on the stack
    tempZombie.announce();   // Call the announce method
    
    return;                  
    // Function ends, tempZombie goes out of scope and is destroyed
}
