#include "Contact.hpp"
#include <iostream>


/* --- Constructors and Destructors --- */


Contact::Contact() {}

Contact::~Contact() {}


/* --- Getter Functions --- */


std::string Contact::getFirstName() const { return firstName; }

std::string Contact::getLastName() const { return lastName; }

std::string Contact::getNickName() const { return nickName; }

std::string Contact::getPhoneNumber() const { return phoneNumber; }

std::string Contact::getDarkestSecret() const { return darkestSecret; }

std::string	Contact::getField(int idx) const
{
	switch (idx)
	{
		case 0: return getFirstName();
		case 1: return getLastName();
		case 2: return getNickName();
		case 3: return getPhoneNumber();
		case 4: return getDarkestSecret();
		default: return "\t????\n";
	}
}


/* --- Setter Functions --- */


bool	Contact::setFirstName(const std::string& val)
{
	if (val.empty())
	{
		std::cout << "Error! Please Enter your First Name!" << std::endl;
		return false;
	}
	firstName = val;
	return true;
}

bool	Contact::setLastName(const std::string& val)
{
	if (val.empty())
	{
		std::cout << "Error! Please Enter your Last Name!" << std::endl;
		return false;
	}
	lastName = val;
	return true;
}

bool	Contact::setNickName(const std::string& val)
{
	if (val.empty())
	{
		std::cout << "Error! Please Enter your Nick Name!" << std::endl;
		return false;
	}
	nickName = val;
	return true;
}

bool	Contact::setPhoneNumber(const std::string& val)
{
	if (val.empty())
	{
		std::cout << "Error! Please Enter your Phone Number!" << std::endl;
		return false;
	}
	phoneNumber = val;
	return true;
}

bool	Contact::setDarkestSecret(const std::string& val)
{
	if (val.empty())
	{
		std::cout << "Error! Please Enter your Darkest Secret!" << std::endl;
		return false;
	}
	darkestSecret = val;
	return true;
}

bool Contact::setField(int idx, const std::string &val)
{
	switch (idx)
	{
		case 0: return setFirstName(val);
		case 1: return setLastName(val);
		case 2: return setNickName(val);
		case 3: return setPhoneNumber(val);
		case 4: return setDarkestSecret(val);
		default: return false;
	}
}

// bool Contact::setAllAttributes()
// {
// 		bool working = true;
// 		std::string input = getUserInputs();
// 		if (input.empty())
// 		{
// 			return false;
// 		}
// 		firstName = input;
// 		input = getUserInputs();
// }
