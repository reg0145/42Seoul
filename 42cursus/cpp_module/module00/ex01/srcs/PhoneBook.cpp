#include "../includes/PhoneBook.h"

PhoneBook::PhoneBook() : index_(0), size_(0) {}

Contact *PhoneBook::GetContacts() {
	return this->contacts_;
}

void    PhoneBook::AddContact(Contact &contact) {
	this->contacts_[this->index_] = contact;
	this->index_ = (this->index_ + 1) % kMaxSize;
	if (this->size_ != kMaxSize)
		this->size_ += 1;
}

int     PhoneBook::GetSize() {
	return this->size_;
}