#include "ContactPhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contact_num = 0;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void PhoneBook::add(void)
{
	Contact new_contact;

	for (int i = MAX_CONTACTS_NUM - 1; i > 0; i--)
	{
		this->_contacts[i] = this->_contacts[i - 1];
	}
	new_contact.setContactInfo();
	this->_contacts[0] = new_contact;
}

void PhoneBook::search()
{
	std::string	input;
	int			index;

	for (int idx = 0; idx < MAX_CONTACTS_NUM; idx++)
	{
		this->_contacts[idx].printContact();
	}
	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	std::istringstream iss()
	if (index < MAX_CONTACTS_NUM && index >= 0)
		this->_contacts[index].printContact();
	else
	std::cout << "Index out of bound!";
}

void PhoneBook::run(void)
{
	std::string command;

	while (true)
	{
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (std::cin.eof())
			break;
		if (command == "ADD")
			this->add();
		else if (command == "SEARCH")
			this->search();
		else if (command == "EXIT")
			break;
		else
			std::cout << "Invalid command!" << std::endl;
	}
}
