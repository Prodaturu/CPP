#include "contact.hpp"
#include <iostream> // Header shouldnt include iostream but displayContact uses it

// Default constructor //
Contact::Contact() : _firstName(""), _lastName(""), _nickname(""), _phoneNumber(""), _darkestSecret("")
{
	// Initializer list initializes all member variables to empty strings
}

// Default destructor //
Contact::~Contact() {}

/*Getters and Setters*/

// Getters //

std::string Contact::getFirstName() const
{
	return _firstName;
}

std::string Contact::getLastName() const
{
	return _lastName;
}

std::string Contact::getNickname() const
{
	return _nickname;
}

std::string Contact::getPhoneNumber() const
{
	return _phoneNumber;
}

std::string Contact::getDarkestSecret() const
{
	return _darkestSecret;
}

// Setters //

void Contact::setFirstName(const std::string &firstName)
{
	_firstName = firstName;
}

void Contact::setLastName(const std::string &lastName)
{
	_lastName = lastName;
}

void Contact::setNickname(const std::string &nickname)
{
	_nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber)
{
	_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret)
{
	_darkestSecret = darkestSecret;
}

/*Other Methods*/

// Display contact information //
void Contact::displayContact() const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}

/** Reason why header should not include iostream
 * 
 * If the header file includes <iostream>
 * Every source file that includes contact.hpp would also include <iostream>
 * This can lead to longer compilation times and unnecessary dependencies
 * If multiple source files include contact.hpp
 * they would all include <iostream> as well
 * 
 * By including <iostream> only in contact.cpp
 * we limit the inclusion to where it's actually needed
 * This keeps the header file cleaner and reduces compilation dependencies
 */
