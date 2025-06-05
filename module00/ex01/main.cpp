#include "ContactPhoneBook.hpp"


int	main(void)
{
	std::string command;
	PhoneBook	pb;

	while (true)
	{
		std::cout << "Enter command: ";

		if (!std::getline(std::cin, command))
			break ;
		if (command == "ADD")
			pb.add();
		else if (command == "SEARCH")
			pb.search();
		else if (command == "EXIT")
			break;
		else if (!command.empty())
			std::cout << "Invalid command!" << std::endl;
	}
	return (0);
}
