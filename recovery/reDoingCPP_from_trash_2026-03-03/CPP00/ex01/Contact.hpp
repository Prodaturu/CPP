#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		// string for number, so we can format different types & have no size
		// limitations
		std::string phoneNumber;
		std::string darkestSecret;

	public:
		Contact();
		~Contact();

		/* Getter functions (const-correct) */
		std::string getFirstName() const;
		std::string getLastName() const;
		std::string getNickName() const;
		std::string getPhoneNumber() const;
		std::string getDarkestSecret() const;

		/* Setter functions -- return true if value accepted */
		bool setFirstName(const std::string& val);
		bool setLastName(const std::string& val);
		bool setNickName(const std::string& val);
		bool setPhoneNumber(const std::string& val);
		bool setDarkestSecret(const std::string& val);
		// bool setAllAttributes();

		/* Helper functions*/

		// Function to parse string PhoneNumber's to numerical


		/* Optional generic accessors (indexed) */
		std::string getField(int idx) const;            // 0..4
		bool setField(int idx, const std::string& val); // 0..4
};

#endif // CONTACT_HPP
