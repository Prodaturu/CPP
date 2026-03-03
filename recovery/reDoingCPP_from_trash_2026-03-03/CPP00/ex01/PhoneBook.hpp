#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		contactCount = 0;
		int		nextIndex = 0;

	public:
		PhoneBook();
		~PhoneBook();

		/* --- Helper Functions --- */
		// Prompt user and add new contact //
		void	addContact();
		
		// Display before user gives index of specific contact
		void	displaySearchContacts() const;
		
		// Search a specific contact
		void	displayContact(int userIndex) const;
		
		// function that runs the main logic
		void	mainLoop(int idx) const;
};

#endif // PHONEBOOK_HPP