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

    Zombie();                                    // Default constructor (needed for arrays)
    Zombie(const std::string& name);             // Constructor with name
    ~Zombie();                                   // Destructor

/* --- Helper Functions --- */

    void announce(void);                         // Fn announcing zombie's name
    void setName(const std::string& name);       // Set zombie name (needed for horde)

};

/* --- Stand alone functions --- */

Zombie* zombieHorde(int N, const std::string& name);  // Create horde of N zombies

#endif // ZOMBIE_HPP