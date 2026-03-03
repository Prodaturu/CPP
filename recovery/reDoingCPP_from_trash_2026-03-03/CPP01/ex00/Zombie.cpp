#include "Zombie.hpp"
#include <iostream>

/* --- Constructor --- */
Zombie::Zombie(const std::string& name) : _name(name)
{
    std::cout << _name << " has been created." << std::endl;
}

/* --- Destructor --- */
Zombie::~Zombie()
{
    std::cout << _name << " has been destroyed." << std::endl;
}

/* --- Member Function --- */
void Zombie::announce(void)
{
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
