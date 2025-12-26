#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
private:
	std::string _firstName, _lastName, _nickname, _phoneNumber, _darkestSecret;

public:
	/*ctor and dtor*/

	// default ctor and default dtor
	Contact();
	~Contact();

	/*Getters and Setters*/

	// Getters
	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;

	// Setters
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

	/*Other Methods*/
	void displayContact() const;
};

#endif // CONTACT_HPP