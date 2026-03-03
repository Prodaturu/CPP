#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

// Zombie class implementation //
class Zombie
{
    private:
        std::string _name;

    public:

/* --- Constructors and Destructor --- */

    Zombie(const std::string& name);	// Constructor with name

    ~Zombie(); 					// Destructor

/* --- Helper Functions --- */

    void	announce(void);					// Fn announcing zombie's name

};

/* --- Stand alone functions --- */

Zombie* 	newZombie(const std::string& name);	// 1. Create new Zombie on heap & return it's pointer

void		randomChump(const std::string& name);	// 2. Creates new Zombie on stack & announce itself


#endif
