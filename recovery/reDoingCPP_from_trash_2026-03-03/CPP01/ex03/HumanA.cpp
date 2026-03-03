#include "HumanA.hpp"
#include "Weapon.hpp"

// Constructor with name and weapon reference //
HumanA::HumanA(const std::string& n, Weapon& w) : name(n), weapon(w) {}

// Destructor //
HumanA::~HumanA() {}

// attack function that displays attack message //
void	HumanA::attack() const
{
	std::cout << name << " attacks with their "
		<< weapon.getType() << std::endl;
}

// HumanA always has a weapon as it's passed by reference in constructor
