#include "ContactPhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contact_num = 0;
}

PhoneBook::~PhoneBook(void)
{
	;
}

void	PhoneBook::add(void)
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

void	PhoneBook::search()
{
	std::string	input;
	int			index;

	if (!this->_contact_num)
	{
		std::cout << "Nothing to show." << std::endl;
		return ;
	}
	for (int i = 0; i < this->_contact_num && i < MAX_CONTACTS_NUM; i++)
		this->_contacts[i].printContact();
	while (1)
	{
		std::cout << "Enter an index: ";
		if (!std::getline(std::cin, input))
			exit(1) ;
		if (Contact::checkInput(input, true))
		{
			std::istringstream(input) >> index;
			if (index < MAX_CONTACTS_NUM && index >= 0 && index < this->_contact_num)
			{
				this->_contacts[index].printContact();
				break ;
			}
			else
				std::cout << "Index out of bound!" << std::endl;
		}
	}
}
