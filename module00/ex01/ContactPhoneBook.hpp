#ifndef CONTACTPHONEBOOK_H
# define CONTACTPHONEBOOK_H

#include <string>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string_view>
#include <limits>
#include <sstream>

#define MAX_CONTACTS_NUM 3

class	Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
		std::string	_getUserInput(std::string prompt);

	public:
		Contact(void);
		Contact(std::string fname, std::string lname,
				std::string nname, std::string pnumber,
				std::string dsecret);
		~Contact(void);
		
		void		setContactInfo(void);
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;

		bool		checkInput(std::string input, bool is_number);
		void		printContact(void);
};

class PhoneBook
{
	private:
		Contact _contacts[MAX_CONTACTS_NUM];
		int		_contact_num;

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void	run(void);
		void	add(void);
		void	search(void);
};

#endif