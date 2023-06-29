#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
	public:
		PhoneBook();

		void    AddContact(Contact&);
		int     GetSize();
		Contact *GetContacts();

	private:
		static const int    kMaxSize = 8;

		int     index_;
		int     size_;
		Contact contacts_[kMaxSize];
};

#endif
