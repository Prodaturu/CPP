// create two classes: HumanA and HumanB. They both have a Weapon and
// a name. They also have a member function attack() that displays (without the angle
// brackets):
// <name> attacks with their <weapon type>
// HumanA and HumanB are almost identical except for these two small details:
// • While HumanA takes the Weapon in its constructor, HumanB does not.
// • HumanB may not always have a weapon, whereas HumanA will always be
// armed.

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

class	HumanA
{
	private:
		std::string		name;				// name of the HumanA
		Weapon&			weapon;				// reference to Weapon object

	public:
		HumanA(const std::string& n, Weapon& w);	// Constructor with name and weapon reference
		~HumanA();									// Destructor

		void	attack() const;						// attack function that displays attack message
};

#endif // HUMANA_HPP