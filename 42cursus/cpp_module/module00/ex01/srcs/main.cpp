#include <iostream>
#include <iomanip>
#include "../includes/Contact.h"
#include "../includes/PhoneBook.h"

static void RunCommand(std::string cmd, PhoneBook& phoneBook);
static void Input(const std::string output, int& input);
static void Input(const std::string output, std::string& input);
static bool IsSpace(std::string str);
static std::string LimitStringLength(std::string str);

int main(void)
{
	std::string cmd;
	PhoneBook phoneBook;

	while (true) {
		Input("input command(ADD, SEARCH, EXIT) :", cmd);
		RunCommand(cmd, phoneBook);
		std::cout << std::endl;
	}
}

static void Input(const std::string output, int& input) {
	std::cout << output;
	std::cin >> input;
}

static void Input(const std::string output, std::string& input) {
	while (true) {
		std::cout << output;
		std::getline(std::cin, input);
		if (input.empty()) {
			std::cout << "Empty string is not allowed.\n" << std::endl;
			continue;
		}
		if (IsSpace(input)) {
			std::cout << "Empty string is not allowed.\n" << std::endl;
			continue;
		}
		break;
	}
}

static void RunCommand(std::string cmd, PhoneBook& phoneBook) {
	if (cmd == "ADD") {
		Contact contact;
		std::string temp;

		Input("intput firstName : ", temp);
		contact.SetFirstName(temp);
		Input("intput lastName : ", temp);
		contact.SetLastName(temp);
		Input("intput nickName : ", temp);
		contact.SetNickName(temp);
		Input("intput phoneNumber : ", temp);
		contact.SetPhoneNumber(temp);
		Input("intput darkestSecret : ", temp);
		contact.SetDarkestSecret(temp);
		phoneBook.AddContact(contact);
	}
	else if (cmd == "SEARCH") {
		Contact* contacts = phoneBook.GetContacts();

		/* Contract 개수가 없을 경우*/
		int size = phoneBook.GetSize();
		if (size == 0) {
			std::cout << "Please add a contact" << std::endl;
			return ;
		}

		/* Contracts 테이블 출력 */
		std::cout << std::setw(10) << "index" <<  "|";
		std::cout << std::setw(10) << "first name" << "|";
		std::cout << std::setw(10) << "last name" << "|";
		std::cout << std::setw(10) << "nickname" << std::endl;

		for (int i = 0; i < size; i++) {
			std::cout << std::setw(10) << i << " ";
			std::cout << std::setw(10) << LimitStringLength(contacts[i].GetFirstName()) << " ";
			std::cout << std::setw(10) << LimitStringLength(contacts[i].GetLastName()) << " ";
			std::cout << std::setw(10) << LimitStringLength(contacts[i].GetNickName()) << std::endl;
		}

		/* Contract index를 입력받고 출력 */
		int index;
		while (true) {
			std::cout << std::endl;
			Input("Select Index : ", index);
			if (!std::cin || index < 0 || index > (phoneBook.GetSize() - 1)) {
				std::cin.clear();
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "Invalid index value!" << std::endl;
			}
			else {
				std::cin.ignore(INT_MAX, '\n');
				std::cout << "First Name : " << contacts[index].GetFirstName() << std::endl;
				std::cout << "Last Name : " << contacts[index].GetLastName() << std::endl;
				std::cout << "NickName : " << contacts[index].GetNickName() << std::endl;
				std::cout << "PhoneNumber : " << contacts[index].GetPhoneNumber() << std::endl;
				std::cout << "Darkest Secret : " << contacts[index].GetDarkestSecret() << std::endl;
				break ;
			}
		}
	}
	else if (cmd =="EXIT") {
		std::cout << "EXIT" << std::endl;
		exit(0);
	}
}

static std::string LimitStringLength(std::string str) {
	return (str.length() >= 10) ? (str.substr(0, 9) + '.') : str;
}

static bool IsSpace(std::string str) {
	bool is_space = true;
	int length = str.length();

	for (int i = 0; i < length; i++) {
		if (!std::isspace(str[i]))
			is_space = false;
	}
	return (is_space);
}
