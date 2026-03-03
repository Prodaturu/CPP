#include "HumanB.hpp"
#include "Weapon.hpp"

// Constructor with name only //
HumanB::HumanB(const std::string& n) : name(n), weapon(nullptr) {}

// Destructor //
HumanB::~HumanB() {}

// Sets the weapon using a reference //
void	HumanB::setWeapon(Weapon& w)
{
	weapon = &w; // store the address of the weapon passed by reference
}

// attack function that displays attack message //
void	HumanB::attack() const
{
	if (weapon) // check if weapon is not null
	{
		std::cout << name << " attacks with their "
			<< weapon->getType() << std::endl; // use arrow operator to access getType
	}
	else
	{
		std::cout << name << " has no weapon to attack." << std::endl;
	}
}
