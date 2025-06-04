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
	this->_contact_num++;
}

void PhoneBook::search()
{
	std::string	input;
	int			index;

	for (int i = 0; i < MAX_CONTACTS_NUM; i++)
	{
		this->_contacts[i].printContact();
	}
	std::cout << "Enter an index: ";
	std::cin >> input;
	if (this->_contacts[0].checkInput(input, true))
	{
		std::istringstream(input) >> index;
		if (index < MAX_CONTACTS_NUM && index >= 0 && index < this->_contact_num)
			this->_contacts[index].printContact();
		else
			std::cout << "Index out of bound!" << std::endl;
	}
}

void PhoneBook::run(void)
{
	std::string command;

	while (true)
	{
		std::cout << "Enter command: ";
		std::cin >> command;

		if (std::cin.eof())
			break;
		if (command == "ADD")
			this->add();
		else if (command == "SEARCH")
			this->search();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Invalid command!" << std::endl;
	}
}
