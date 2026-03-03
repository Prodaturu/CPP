#include "Weapon.hpp"

/* --- Constructor & Destructor --- */
Weapon::Weapon(const std::string& t) : type(t) {}

Weapon::~Weapon() {}


/* --- Getter and Setter --- */
const std::string& Weapon::getType() const
{
	return this->type;
}

void Weapon::setType(const std::string& newType)
{
	this->type = newType;
}

