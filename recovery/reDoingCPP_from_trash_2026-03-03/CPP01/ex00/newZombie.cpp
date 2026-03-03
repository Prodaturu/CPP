#include "Zombie.hpp"

// This function creates a zombie, names it, and returns it
// can be used outside of the function scope

Zombie* newZombie(const std::string& name)
{
    // Create a Zombie on heap memory
    Zombie* heapZombie = new Zombie(name);

    return heapZombie;
}
