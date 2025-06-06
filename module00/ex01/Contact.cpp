#include "ContactPhoneBook.hpp"

Contact::Contact(void)
{
	;
}

Contact::Contact(std::string fname, std::string lname,
				std::string nname, std::string pnumber,
				std::string dsecret)
				:	_firstName(fname), _lastName(lname), _nickname(nname),
					_phoneNumber(pnumber), _darkestSecret(dsecret)
{
	;
}

Contact::~Contact(void)
{
	;
}

std::string Contact::getFirstName(void) const
{
	return this->_firstName;
}

std::string Contact::getLastName(void) const
{
	return this->_lastName;
}

std::string Contact::getNickname(void) const
{
	return this->_nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret(void) const
{
	return this->_darkestSecret;
}

bool	Contact::_isEmpty(std::string input)
{
	bool	is_char;

	if (input.empty())
	{
		std::cout << "This field can't be left empty!" << std::endl;
		return (true);
	}
	is_char = false;
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (!is_char && !std::isspace(input[i]))
			is_char = true;
	}
	if (is_char)
		return (false);
	else
	{
		std::cout << "This field can't be left empty!" << std::endl;
		return (true);
	}
}

bool	Contact::_isNumber(std::string input)
{
	for (int i = 0; i < (int)input.length(); i++)
	{
		if (!std::isdigit(input[i]))
		{
			std::cout << "Please enter a number!" << std::endl;
			return (false);
		}
	}
	return (true);
}

bool	Contact::checkInput(std::string input, bool isNumber)
{
	if (_isEmpty(input))
		return (false);
	if (isNumber && !_isNumber(input))
		return (false);
	return (true);
}

std::string	Contact::_getUserInput(std::string prompt)
{
	std::string input;

	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
			exit(1) ;
		if (this->checkInput(input, prompt == "Phone number: "))
			return (input);
	}
}

void	Contact::setContactInfo(void)
{
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

	this->_firstName = this->_getUserInput("First name: ");
	this->_lastName = this->_getUserInput("Last name: ");
	this->_nickname = this->_getUserInput("Nickname: ");
	this->_phoneNumber = this->_getUserInput("Phone number: ");
	this->_darkestSecret = this->_getUserInput("Darkest secret: ");
}

void	Contact::printContact()
{
	std::cout << std::right << std::setw(10) << (this->getFirstName().size() <= 10 ? this->getFirstName() : this->getFirstName().substr(0, 9) + ".") << "|";
	std::cout << std::right << std::setw(10) << (this->getLastName().size() <= 10 ? this->getLastName() : this->getLastName().substr(0, 9) + ".") << "|";
	std::cout << std::right << std::setw(10) << (this->getNickname().size() <= 10 ? this->getNickname() : this->getNickname().substr(0, 9) + ".") << "|";
	std::cout << std::right << std::setw(10) << (this->getPhoneNumber().size() <= 10 ? this->getPhoneNumber() : this->getPhoneNumber().substr(0, 9) + ".");
	std::cout << std::endl;
}