#include "phonebook.hpp"
#include <iostream>

int main()
{
	phonebook 		myPhoneBook;
	std::string 	userInput;

	while ("CPP is cool")
	{
		std::cout << " Enter a command dude (ADD, SEARCH, EXIT): ";

		std::getline(std::cin, userInput);
		if (std::cin.eof())
			break ;
		
	}
	return 0;
}
