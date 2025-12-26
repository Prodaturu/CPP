#ifndef PhoneBook_HPP
#define PhoneBook_HPP

#include "contact.hpp"
#include <string>

class phonebook
{
private:
	/* data */
	Contact	_contacts[8];		// Array to hold up to 8 contacts
	int 	_contactCount;		// Number of contacts currently stored
	int		_index;				// Next index to add a contact

public:
/* --- --- --- ctor and dtor --- --- --- */
	phonebook();
	~phonebook();


/* --- --- --- setters and getters --- --- --- */
	// Setters
	void	addContact(int index, Contact contact);

	// Getters
	Contact	displayContact(int index) const;

/* --- --- --- Helper methods --- --- --- */
	void	displayContacts() const;
};

#endif // PhoneBook_HPP