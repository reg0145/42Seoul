
#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
	public:
		std::string GetFirstName();
		void        SetFirstName(std::string);
		std::string GetLastName();
		void        SetLastName(std::string);
		std::string GetNickName();
		void        SetNickName(std::string);
		std::string GetPhoneNumber();
		void        SetPhoneNumber(std::string);
		std::string GetDarkestSecret();
		void        SetDarkestSecret(std::string);

	private:
		std::string first_name_;
		std::string last_name_;
		std::string nickname_;
		std::string phone_number_;
		std::string darkest_secret_;
};

#endif