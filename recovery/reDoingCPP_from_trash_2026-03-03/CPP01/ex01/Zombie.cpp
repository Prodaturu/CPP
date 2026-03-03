#include "Zombie.hpp"
#include <iostream>

// Default Constructor (needed for arrays)
Zombie::Zombie() : _name("Unnamed")
{
    std::cout << "Unnamed zombie has been created." << std::endl;
}

// Constructor with name param
Zombie::Zombie(const std::string& name) : _name(name)
{
    std::cout << _name << " has been created." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

/* --- Member Functions --- */
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(const std::string& name)
{
    _name = name;
}
