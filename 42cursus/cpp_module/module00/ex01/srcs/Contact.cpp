#include "../includes/Contact.h"

std::string Contact::GetFirstName()
{
	return this->first_name_;
}

void Contact::SetFirstName(std::string first_name)
{
	this->first_name_ = first_name;
}

std::string Contact::GetLastName() {
	return this->last_name_;
}

void Contact::SetLastName(std::string last_name) {
	this->last_name_ = last_name;
}

std::string Contact::GetNickName() {
	return this->nickname_;
}

void Contact::SetNickName(std::string nick_name) {
	this->nickname_ = nick_name;
}

std::string Contact::GetPhoneNumber() {
	return this->phone_number_;
}

void Contact::SetPhoneNumber(std::string phone_number) {
	this->phone_number_ = phone_number;
}

std::string Contact::GetDarkestSecret() {
	return this->darkest_secret_;
}

void Contact::SetDarkestSecret(std::string darkest_secret) {
	this->darkest_secret_ = darkest_secret;
}
