#include "PhoneBook.hpp"
#include <iostream>
#include <cctype>

std::string	parseRequest(std::string str)
{
	std::string	upperParsed;

	upperParsed = str;
	for (size_t i = 0; i < upperParsed.length(); i++)
	{
		upperParsed[i] = std::toupper(static_cast<unsigned char>(upperParsed[i]));
	}
	return	upperParsed;
}

/** Logic of main function
 * 
 * 1. Create an empty phonebook (has no contacts yet)
 * 2. Ask for user input in a infinite and ask for user input
 * 		- so we can prompt user after handling the request and stop if exit
 * 3. Parse the input from user and do the respective job
 * 4. Return 0 on exit
 */
int main()
{
	PhoneBook contactsList;

	while ("Jaggy") // redability is not a concern so "jaggy" is fine as its truthy
	{
		std::string	userRequest;
		std::cout << "\nEnter your choice\n1. ADD\t2. SEARCH\t3. EXIT" << std::endl;
		if(!std::getline(std::cin, userRequest))
		{
			std::cin.clear();
			continue;
		}
		
		userRequest = parseRequest(userRequest);
		if (userRequest == "ADD")
			contactsList.addContact();
		else if (userRequest == "SEARCH")
			contactsList.displaySearchContacts();
		else if (userRequest == "EXIT")
			return 0;
		else
			continue;
	}
	return (0);
}