#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>


// Weapon class that has:
class Weapon
{
	private:
		std::string		type;			// private attribute type, string

	public:
		/* Constructors and Destructors */

		Weapon(const std::string& t);		// Constructor initializing a weapon type
		~Weapon();						// Destructor

		/* Getter and Setter */

		const std::string&	getType() const; 			// Returns a constant reference to type
		void	setType(const std::string& newType);	// Sets type using new value
};

#endif

// ** Implement a Weapon class that has: ** //
// • A private attribute type, which is a string.
// • A getType() member function that returns a constant reference to type.
// • A setType() member function that sets type using the new value passed as a parameter.

/**
 * Definition of Constant Reference:
 * Reference which can't be used to modify the variable it refers to -> Const Reference
 * Is declared using the const keyword before the type of the reference.
 * Example: const int& ref = var;
 * Benefits:
 * 1. Efficiency: Avoids copying large objects, improving performance.
 * 2. Safety: Prevents accidental modification of the original variable.
 * 3. Flexibility: Can bind to temporary objects and literals.
 */
