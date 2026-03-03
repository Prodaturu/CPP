// create two classes: HumanA and HumanB. They both have a Weapon and
// a name. They also have a member function attack() that displays (without the angle
// brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost identical except for these two small details:
// • While HumanA takes the Weapon in its constructor, HumanB does not.
// • HumanB may not always have a weapon, whereas HumanA will always be
// armed.

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class	HumanB
{
	private:
		std::string		name;				// name of the HumanB
		Weapon*			weapon;				// pointer to Weapon object

	public:
		HumanB(const std::string& n);			// Constructor with name only
		~HumanB();								// Destructor

		void	setWeapon(Weapon& w);			// Sets the weapon using a reference
		void	attack() const;					// attack function that displays attack message
};

#endif // HUMANB_HPP
