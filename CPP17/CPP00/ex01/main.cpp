#include "phonebook.hpp"
#include <iostream>

int main()
{
	phonebook 		myPhoneBook;
	std::string 	userInput;

	// Infinite loop till user exits
	while ("CPP is cool")
	{
		/** Logic for user commands
		 * ADD 	- Add a new contact
		 * SEARCH 	- Search existing contacts
		 * EXIT 	- Exit the program
		 * 
		 * any other input is considered invalid
		 * 
		 * each command is handled with appropriate phonebook methods
		 * 
		 * In main we just:
		 * 	prompt user for next command
		 * 	then depending on input, call the relevant methods
		 * 	deal with EOF to exit gracefully
		 */

		std::cout << " Enter a command dude (ADD, SEARCH, EXIT): ";

		std::getline(std::cin, userInput);
		if (std::cin.eof())
			break ;
			
		if (userInput == "ADD")
		{
			// Call method to add a new contact
			myPhoneBook.addContact();
		}
		else if (userInput == "SEARCH")
		{
			// Call method to search existing contacts
			myPhoneBook.searchContacts();
		}
		else if (userInput == "EXIT")
		{
			// Exit the program on demand
			std::cout << "Exiting phonebook. Goodbye!" << std::endl;
			break ;
		}
		else
		{
			// Handle invalid commands
			std::cout << " Invalid command. Please try again." << std::endl;
		}
	}
	return (0);
}
