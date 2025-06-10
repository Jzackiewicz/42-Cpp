#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string &stringREF = str;
	
	std::cout << "String address: " << &str << std::endl;
	std::cout << "Pointer address: " << &stringPTR << std::endl;
	std::cout << "Reference adress: " << &stringREF << std::endl;

	std::cout << "String: " << str << std::endl;
	std::cout << "Pointer: " << *stringPTR << std::endl;
	std::cout << "Reference: " << stringREF << std::endl;

	return (0);
}
