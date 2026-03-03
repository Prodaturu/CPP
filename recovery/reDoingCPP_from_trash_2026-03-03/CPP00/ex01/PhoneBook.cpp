
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>


/* --- Constructor and Destructor --- */


PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

// helper: fit string into width 10, replacing last char with '.' when truncated
static std::string	fit(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}


/* --- Main Functions --- */


// Add's a new contact
void	PhoneBook::addContact()
{
	Contact		newContact;
	std::string	input;

	// Get input's & set all field's of Contact class

	std::cout << "Enter First Name: ";
	while (std::getline(std::cin, input) && !newContact.setFirstName(input))
	{
		std::cout << "Field cannot be empty! Enter First Name again: ";
	}

	std::cout << "Enter Last Name: ";
	while (std::getline(std::cin, input) && !newContact.setLastName(input))
	{
		std::cout << "Field cannot be empty! Enter Last Name again: ";
	}

	std::cout << "Enter Nickname: ";
	while (std::getline(std::cin, input) && !newContact.setNickName(input))
	{
		std::cout << "Field cannot be empty! Enter Nickname again: ";
	}

	std::cout << "Enter Phone Number: ";
	while (std::getline(std::cin, input) && !newContact.setPhoneNumber(input))
	{
		std::cout << "Field cannot be empty! Enter Phone Number again: ";
	}

	std::cout << "Enter Darkest Secret: ";
	while (std::getline(std::cin, input) && !newContact.setDarkestSecret(input))
	{
		std::cout << "Field cannot be empty! Enter Darkest Secret again: ";
	}

	// Add the new contact to the phone book
	contacts[nextIndex] = newContact;

	// track the newIndex after adding contact
	nextIndex = (nextIndex + 1) % 8;

	// keeping track of Total No of Contacts
	if (contactCount < 8)
		contactCount++;
}

// 
void	PhoneBook::displaySearchContacts() const

{
		//-------------------------------------------------------//
		/* 			Part 1 : Code to print the table             */
		//-------------------------------------------------------//	

	if (contactCount == 0)
	{
		std::cout << "There are no contacts to display!\nNeed to have contact(s) to search"<<std::endl;
		return ;
	}

	std::cout << "\n";
	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < contactCount; ++i)
	{
		std::cout << "|" << std::setw(10) << i + 1
				  << "|" << std::setw(10) << fit(contacts[i].getFirstName())
				  << "|" << std::setw(10) << fit(contacts[i].getLastName())
				  << "|" << std::setw(10) << fit(contacts[i].getNickName())
				  << std::endl;
	}

		//---------------------------------------------------------------//
		/*   Part 2: Get index & print info of contact at given Index   */
		//--------------------------------------------------------------//

	// ask for the exact index and re-prompt until a valid input is entered
	int chosen = 0;
	while ("Jaggy")
	{
		std::string line; // stores the user input
		std::cout << "Enter index (1-" << contactCount << ") or press Enter to cancel: ";
		if (!std::getline(std::cin, line))
		{
			std::cin.clear();
			return;
		}

		// trim whitespace
		size_t s = line.find_first_not_of(" \t\r\n");
		if (s == std::string::npos)
			return; // empty -> cancel
		size_t e = line.find_last_not_of(" \t\r\n");
		std::string t = line.substr(s, e - s + 1);

		// require exactly one character and a digit
		if (t.size() != 1 || !std::isdigit(static_cast<unsigned char>(t[0])))
		{
			std::cout << "Please enter exactly one digit between 1 and " << contactCount << "." << std::endl;
			continue;
		}

		int idx = t[0] - '0';
		if (idx < 1 || idx > contactCount)
		{
			std::cout << "Index out of range (1-" << contactCount << ")" << std::endl;
			continue;
		}

		chosen = idx;
		break;
	}
	// display the information at the chosen index
	if (chosen)
		displayContact(chosen);
}

// Displays data of specified contact
void	PhoneBook::displayContact(int userIndex) const
{
	int	actualIndex;
	actualIndex = userIndex - 1;

	if (actualIndex >=0 && actualIndex < contactCount)
	{
		std::cout << std::endl;
		std::cout << "Index:          " << actualIndex + 1 << std::endl;
		std::cout << "First Name:     " << contacts[actualIndex].getFirstName() << std::endl;
		std::cout << "Last Name:      " << contacts[actualIndex].getLastName() << std::endl;
		std::cout << "Nick Name:      " << contacts[actualIndex].getNickName() << std::endl;
		std::cout << "Phone Number:   " << contacts[actualIndex].getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << contacts[actualIndex].getDarkestSecret() << std::endl;
	}
	else
	{
		std::cout << "ERROR! The Index is invalid!";
		return ;
	}
	return ;
}